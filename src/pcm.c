#include <alsa/asoundlib.h>
#include <sndio.h>
#include <poll.h>
#include <stdbool.h>
#include <assert.h>
#include "util/dsp.h"
#include "util/util.h"

static const struct format_info {
   const char *name;
   snd_pcm_format_t fmt;
   struct sio_enc enc;
} SUPPORTED_FORMATS[] = {
#define FMT(F, BITS, BPS, SIG, LE, MSB) { .name = #F, .fmt = F, .enc = { .bits = BITS, .bps = BPS, .sig = SIG, .le = LE, .msb = MSB } }
   FMT(SND_PCM_FORMAT_S8, 8, 1, 1, 1, 1),
   FMT(SND_PCM_FORMAT_U8, 8, 1, 0, 1, 1),
   FMT(SND_PCM_FORMAT_S16_LE, 16, 2, 1, 1, 1),
   FMT(SND_PCM_FORMAT_S16_BE, 16, 2, 1, 0, 1),
   FMT(SND_PCM_FORMAT_U16_LE, 16, 2, 0, 1, 1),
   FMT(SND_PCM_FORMAT_U16_BE, 16, 2, 0, 0, 1),
   FMT(SND_PCM_FORMAT_S24_3LE, 24, 3, 1, 1, 1),
   FMT(SND_PCM_FORMAT_S24_3BE, 24, 3, 1, 0, 1),
   FMT(SND_PCM_FORMAT_U24_3LE, 24, 3, 0, 1, 1),
   FMT(SND_PCM_FORMAT_U24_3BE, 24, 3, 0, 0, 1),
   FMT(SND_PCM_FORMAT_S32_LE, 24, 4, 1, 1, 1),
   FMT(SND_PCM_FORMAT_S32_BE, 24, 4, 1, 0, 1),
   FMT(SND_PCM_FORMAT_U32_LE, 24, 4, 0, 1, 1),
   FMT(SND_PCM_FORMAT_U32_BE, 24, 4, 0, 0, 1),
   FMT(SND_PCM_FORMAT_FLOAT_LE, 32, 4, 1, 1, 0), // always transcoded
   FMT(SND_PCM_FORMAT_FLOAT_BE, 32, 4, 1, 0, 0) // always transcoded
#undef FMT
};

const struct format_info*
format_info_for_sio_enc(const struct sio_enc *enc)
{
   for (size_t i = 0; i < ARRAY_SIZE(SUPPORTED_FORMATS); ++i) {
      if (!memcmp(enc, &SUPPORTED_FORMATS[i].enc, sizeof(*enc)))
         return &SUPPORTED_FORMATS[i];
   }
   return NULL;
}

const struct format_info*
format_info_for_format(const snd_pcm_format_t format)
{
   for (size_t i = 0; i < ARRAY_SIZE(SUPPORTED_FORMATS); ++i) {
      if (SUPPORTED_FORMATS[i].fmt == format)
         return &SUPPORTED_FORMATS[i];
   }
   return NULL;
}

snd_pcm_format_t
snd_pcm_format_value(const char* name)
{
   for (size_t i = 0; i < ARRAY_SIZE(SUPPORTED_FORMATS); ++i) {
      if (!strcmp(SUPPORTED_FORMATS[i].name, name))
         return SUPPORTED_FORMATS[i].fmt;
   }
   return SND_PCM_FORMAT_UNKNOWN;
}

const char*
snd_pcm_format_name(const snd_pcm_format_t format)
{
   const struct format_info *info = format_info_for_format(format);
   return (info ? info->name : NULL);
}

int
snd_pcm_format_width(snd_pcm_format_t format)
{
   const struct format_info *info = format_info_for_format(format);
   return (info ? (int)info->enc.bits : -1);
}

int
snd_pcm_format_physical_width(snd_pcm_format_t format)
{
   const struct format_info *info = format_info_for_format(format);
   return (info ? (int)info->enc.bps * 8 : -1);
}

ssize_t
snd_pcm_format_size(snd_pcm_format_t format, size_t samples)
{
   return samples * snd_pcm_format_physical_width(format) / 8;
}

struct _snd_pcm_hw_params {
   struct sio_cap cap;
   struct sio_par par;
   struct hw_limits {
      snd_pcm_format_t supported[ARRAY_SIZE(SUPPORTED_FORMATS)];
      unsigned int pchan[2], rchan[2], rate[2];
   } limits;
   snd_pcm_format_t format;
   snd_pcm_access_t access;
   snd_pcm_stream_t stream;
   bool needs_conversion; // for unsupported formats
};

struct _snd_pcm_sw_params { char noop; };

struct _snd_pcm {
   struct _snd_pcm_hw_params hw;
   struct _snd_pcm_sw_params sw;
   struct timespec start_time;
   struct sio_hdl *hdl;
   const char *name;
   snd_pcm_uframes_t position, written, avail;
   int mode;
   bool started;
};

static int
sndio_stream(snd_pcm_stream_t stream)
{
   switch (stream) {
      case SND_PCM_STREAM_PLAYBACK: return SIO_PLAY;
      case SND_PCM_STREAM_CAPTURE: return SIO_REC;
   }
   ERRX(EXIT_FAILURE, "unknown stream: %u", stream);
}

static int
sndio_mode(int mode)
{
   switch (mode) {
      case SND_PCM_NONBLOCK: WARNX1("SND_PCM_NONBLOCK"); return true;
      // ASYNC: SIGIO will be emitted whenever a period has been completely processed by the soundcard.
      case SND_PCM_ASYNC: ERRX1(EXIT_FAILURE, "SND_PCM_ASYNC is not supported");
   }
   return false;
}

static void
onmove(void *arg, int delta)
{
   snd_pcm_t *pcm = arg;
   pcm->position += delta;
   pcm->avail += delta;
}

static struct sio_hdl*
device_open(snd_pcm_t *pcm, const char *name, snd_pcm_stream_t stream, int mode)
{
   const char *sndio_name = (!name || !strcmp(name, "default") ? SIO_DEVANY : name);

   struct sio_hdl *hdl;
   if (!(hdl = sio_open(sndio_name, sndio_stream(stream), sndio_mode(mode))) &&
       !(hdl = sio_open(SIO_DEVANY, sndio_stream(stream), sndio_mode(mode)))) {
      WARNX1("sio_open failed");
      return NULL;
   }

   pcm->mode = mode;
   pcm->hw.stream = stream;
   sio_onmove(hdl, onmove, pcm);
   return hdl;
}

static void
dump_enc(const struct sio_enc *enc, struct hw_limits *limits)
{
   WARNX("- - - bits: %u bps: %u sig: %u le: %u msb: %u", enc->bits, enc->bps, enc->sig, enc->le, enc->msb);
   const struct format_info *info = format_info_for_sio_enc(enc);
   assert(info);
   WARNX("- - - aka %s", info->name);

   size_t i;
   for (i = 0; i < ARRAY_SIZE(limits->supported) && limits->supported[i] != SND_PCM_FORMAT_UNKNOWN; ++i);
   assert(i < ARRAY_SIZE(limits->supported));
   limits->supported[i] = info->fmt;
}

static void
dump_cap(const char *name, const struct sio_cap *cap, struct hw_limits *limits)
{
   *limits = (struct hw_limits){0};
   limits->rate[0] = limits->rchan[0] = limits->pchan[0] = ~(unsigned int)0;
   memset(limits->supported, SND_PCM_FORMAT_UNKNOWN, sizeof(limits->supported));

   WARNX("* %s", name);
   for (unsigned int c = 0; c < cap->nconf; ++c) {
      WARNX("- - configuration %u", c);

      for (unsigned int i = 0; i < SIO_NENC; ++i) {
         if (cap->confs[c].enc & (1 << i))
            dump_enc(&cap->enc[i], limits);
      }

      for (unsigned int i = 0; i < SIO_NCHAN; ++i) {
         if (!(cap->confs[c].rchan & (1 << i)))
            continue;

         WARNX("- - - rchan: %u", cap->rchan[i]);
         limits->rchan[0] = MIN(limits->rchan[0], cap->rchan[i]);
         limits->rchan[1] = MAX(limits->rchan[1], cap->rchan[i]);
      }

      for (unsigned int i = 0; i < SIO_NCHAN; ++i) {
         if (!(cap->confs[c].pchan & (1 << i)))
            continue;

         WARNX("- - - pchan: %u", cap->pchan[i]);
         limits->pchan[0] = MIN(limits->pchan[0], cap->pchan[i]);
         limits->pchan[1] = MAX(limits->pchan[1], cap->pchan[i]);
      }

      for (unsigned int i = 0; i < SIO_NRATE; ++i) {
         if (!(cap->confs[c].rate & (1 << i)))
            continue;

         WARNX("- - - rate: %u", cap->rate[i]);
         limits->rate[0] = MIN(limits->rate[0], cap->rate[i]);
         limits->rate[1] = MAX(limits->rate[1], cap->rate[i]);
      }
   }
}

int
snd_pcm_open(snd_pcm_t **pcm, const char *name, snd_pcm_stream_t stream, int mode)
{
   if (!(*pcm = calloc(1, sizeof(**pcm)))) {
      WARN1("calloc");
      return -1;
   }

   if (!((*pcm)->hdl = device_open(*pcm, name, stream, mode)))
      goto fail;

   sio_initpar(&(*pcm)->hw.par);
   (*pcm)->name = (name ? name : "default");

   if (!sio_getcap((*pcm)->hdl, &(*pcm)->hw.cap) || !sio_getpar((*pcm)->hdl, &(*pcm)->hw.par))
      goto fail;

   dump_cap(name, &(*pcm)->hw.cap, &(*pcm)->hw.limits);
   (*pcm)->hw.format = SND_PCM_FORMAT_UNKNOWN;
   return 0;

fail:
   free(*pcm);
   return -1;
}

int
snd_pcm_close(snd_pcm_t *pcm)
{
   sio_close(pcm->hdl);
   free(pcm);
   return 0;
}

const char*
snd_pcm_name(snd_pcm_t *pcm)
{
   return pcm->name;
}

int
snd_pcm_nonblock(snd_pcm_t *pcm, int nonblock)
{
   if ((pcm->mode == SND_PCM_NONBLOCK && nonblock) || (!pcm->mode && !nonblock))
      return 0;

   WARNX("snd_pcm_nonblock(%d)", nonblock);
   snd_pcm_drain(pcm);
   sio_close(pcm->hdl);

   if (!(pcm->hdl = device_open(pcm, pcm->name, pcm->hw.stream, (nonblock ? SND_PCM_NONBLOCK : false))))
      return -1;

   return snd_pcm_hw_params(pcm, &pcm->hw);
}

int
snd_pcm_poll_descriptors_count(snd_pcm_t *pcm)
{
   return sio_nfds(pcm->hdl);
}

int
snd_pcm_poll_descriptors(snd_pcm_t *pcm, struct pollfd *pfds, unsigned int space)
{
   if (space > (unsigned int)sio_nfds(pcm->hdl))
      return -1;

   return sio_pollfd(pcm->hdl, pfds, (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? POLLOUT : POLLIN));
}

int
snd_pcm_poll_descriptors_revents(snd_pcm_t *pcm, struct pollfd *pfds, unsigned int nfds, unsigned short *revents)
{
   if (!revents || nfds > (unsigned int)sio_nfds(pcm->hdl))
      return -1;

   *revents = sio_revents(pcm->hdl, pfds);
   return 0;
}

snd_pcm_state_t
snd_pcm_state(snd_pcm_t *pcm)
{
   if (pcm->started)
      return SND_PCM_STATE_RUNNING;

   return SND_PCM_STATE_OPEN;
}

int
snd_pcm_wait(snd_pcm_t *pcm, int timeout)
{
   return 1; // we are always ready for io
}

snd_pcm_sframes_t
snd_pcm_bytes_to_frames(snd_pcm_t *pcm, ssize_t bytes)
{
   const unsigned int chans = (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan);
   const int bpf = (pcm->hw.par.bps * chans);
   return bytes / bpf;
}

ssize_t
snd_pcm_frames_to_bytes(snd_pcm_t *pcm, snd_pcm_sframes_t frames)
{
   const unsigned int chans = (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan);
   const int bpf = (pcm->hw.par.bps * chans);
   return frames * bpf;
}

static size_t
io_do(snd_pcm_t *pcm, const void *buffer, const size_t frames, size_t (*io)(struct sio_hdl*, const void*, size_t, void*), void *arg)
{
   if (pcm->hw.needs_conversion) {
      const struct format_info *info = format_info_for_format(pcm->hw.format);
      assert(info);

      struct aparams params[2] = {
         {
            .bps = info->enc.bps,
            .bits = info->enc.bits,
            .le = info->enc.le,
            .sig = info->enc.sig,
            .msb = info->enc.msb
         }, {
            .bps = pcm->hw.par.bps,
            .bits = pcm->hw.par.bits,
            .le = pcm->hw.par.le,
            .sig = pcm->hw.par.sig,
            .msb = pcm->hw.par.msb
         }
      };

      struct conv dec, enc;
      dec_init(&dec, &params[0], (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan));
      enc_init(&enc, &params[1], (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan));

      size_t total_frames = frames, io_bytes = 0;
      unsigned char decoded[4096], encoded[sizeof(decoded)];
      const size_t max_frames = snd_pcm_bytes_to_frames(pcm, sizeof(decoded));
      for (const unsigned char *p = buffer; total_frames > 0;) {
         const int todo_frames = (total_frames > max_frames ? max_frames : total_frames);
         total_frames -= todo_frames;

         // sadly can't function pointer here as some formats may need different parameters for decoder
         if (pcm->hw.format == SND_PCM_FORMAT_FLOAT_LE || pcm->hw.format == SND_PCM_FORMAT_FLOAT_BE) {
            dec_do_float(&dec, (void*)p, decoded, todo_frames);
         } else {
            dec_do(&dec, (void*)p, decoded, todo_frames);
         }

         enc_do(&enc, decoded, encoded, todo_frames);

         const size_t todo_bytes = snd_pcm_frames_to_bytes(pcm, todo_frames);
         io_bytes += io(pcm->hdl, encoded, todo_bytes, arg);
         p += todo_bytes;
      }

      return io_bytes;
   }

   return io(pcm->hdl, buffer, snd_pcm_frames_to_bytes(pcm, frames), arg);
}

static size_t
cb_write(struct sio_hdl *hdl, const void *buffer, size_t bytes, void *arg)
{
   return sio_write(hdl, buffer, bytes);
}

snd_pcm_sframes_t
snd_pcm_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size)
{
   if (pcm->hw.stream != SND_PCM_STREAM_PLAYBACK) {
      WARNX1("trying to write to capture stream :/");
      return 0;
   }

   const snd_pcm_sframes_t ret = snd_pcm_bytes_to_frames(pcm, io_do(pcm, buffer, size, cb_write, NULL));
   pcm->written += ret;
   pcm->avail -= ret;
   return ret;
}

struct transformation {
   unsigned char *ptr, *end;
};

static size_t
cb_transform(struct sio_hdl *hdl, const void *buffer, size_t bytes, void *arg)
{
   struct transformation *trans = arg;
   assert(trans->ptr + bytes <= trans->end);
   memcpy(trans->ptr, buffer, bytes);
   trans->ptr += bytes;
   return bytes;
}

snd_pcm_sframes_t
snd_pcm_readi(snd_pcm_t *pcm, void *buffer, snd_pcm_uframes_t size)
{
   if (pcm->hw.stream != SND_PCM_STREAM_CAPTURE) {
      WARNX1("trying to read from playback stream :/");
      return 0;
   }

   size_t bytes = snd_pcm_frames_to_bytes(pcm, size);
   bytes = sio_read(pcm->hdl, buffer, bytes);

   struct transformation trans = { .ptr = buffer, .end = (unsigned char*)buffer + bytes };
   const snd_pcm_sframes_t ret = snd_pcm_bytes_to_frames(pcm, io_do(pcm, buffer, snd_pcm_bytes_to_frames(pcm, bytes), cb_transform, &trans));
   pcm->written += ret;
   pcm->avail -= ret;
   return ret;
}

snd_pcm_sframes_t
snd_pcm_avail_update(snd_pcm_t *pcm)
{
   struct pollfd pfd[16];
   int nfds = sio_nfds(pcm->hdl);
   assert((unsigned int)nfds < ARRAY_SIZE(pfd));

   nfds = sio_pollfd(pcm->hdl, pfd, (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? POLLOUT : POLLIN));

   // XXX: timeout should be period time/buffer time(?)
   errno = 0;
   while ((nfds = poll(pfd, nfds, -1)) < 0) {
      if (errno == EINVAL) {
         WARNX1("poll EINVAL");
         goto nodata;
      }
   }

   const int revents = sio_revents(pcm->hdl, pfd);
   if (!(revents & POLLOUT) && !(revents & POLLIN))
      goto nodata;

   return (pcm->avail > pcm->hw.par.appbufsz ? pcm->hw.par.appbufsz : pcm->avail);

nodata:
   // NOTE: returning 1, as some programs don't check the return value :/ (namely qwebengine)
   //       thus they SIGFPE by dividing by 0 or -1
   return 1;
}

snd_pcm_sframes_t
snd_pcm_avail(snd_pcm_t *pcm)
{
   return (pcm->avail > pcm->hw.par.appbufsz ? pcm->hw.par.appbufsz : pcm->avail);
}

int
snd_pcm_delay(snd_pcm_t *pcm, snd_pcm_sframes_t *delayp)
{
   if (delayp) *delayp = pcm->written - pcm->position;
   return 0;
}

int
snd_pcm_prepare(snd_pcm_t *pcm)
{
   if (!pcm->started && sio_start(pcm->hdl)) {
      pcm->started = true;
      pcm->written = pcm->position = 0;
      pcm->avail = pcm->hw.par.bufsz;
      clock_gettime(CLOCK_MONOTONIC, &pcm->start_time);
   }

   return (pcm->started ? 0 : -1);
}

int
snd_pcm_start(snd_pcm_t *pcm)
{
   return snd_pcm_prepare(pcm);
}

int
snd_pcm_drain(snd_pcm_t *pcm)
{
   if (pcm->started && sio_stop(pcm->hdl)) {
      pcm->started = false;
      pcm->written = pcm->position = 0;
      pcm->avail = 0;
   }

   return (!pcm->started ? 0 : -1);
}

int
snd_pcm_drop(snd_pcm_t *pcm)
{
   // FIXME: not correct, we need to do emulation
   return snd_pcm_drain(pcm);
}

int
snd_pcm_resume(snd_pcm_t *pcm)
{
   // FIXME: not correct, we need to do emulation
   return snd_pcm_drain(pcm);
}

int
snd_pcm_pause(snd_pcm_t *pcm, int enable)
{
   // FIXME: not correct, we need to do emulation
   return (enable ? snd_pcm_drain(pcm) : snd_pcm_start(pcm));
}

int
snd_pcm_reset(snd_pcm_t *pcm)
{
   return (!snd_pcm_drain(pcm) && !snd_pcm_prepare(pcm) ? 0 : -1);
}

size_t
snd_pcm_hw_params_sizeof(void)
{
   return sizeof(snd_pcm_hw_params_t);
}

void
snd_pcm_hw_params_copy(snd_pcm_hw_params_t *dst, const snd_pcm_hw_params_t *src)
{
   *dst = *src;
}

static bool
apply_par(snd_pcm_t *pcm, const struct sio_par *old, struct sio_par *new_par)
{
   const bool was_started = pcm->started;

   if (was_started)
      snd_pcm_drain(pcm);

   if (!new_par->__magic) {
      // sndio sets magic to 0 after getpar, so it becomes "uninitialized".
      // using "uninitialized" par in setpar fails. however, due to how asound
      // design is, we really want to use our getparred pars in setpar, so
      // lets force the initialized state here.
      struct sio_par tmp;
      sio_initpar(&tmp);
      new_par->__magic = tmp.__magic;
      new_par->bufsz = ~0U; // read-only
   }

   if (!sio_setpar(pcm->hdl, new_par)) {
      WARNX1("sio_setpar failed");
      goto fail;
   }

   struct sio_par hpar;
   if (!sio_getpar(pcm->hdl, &hpar)) {
      WARNX1("sio_getpar failed");
      goto fail;
   }

   *new_par = hpar;
   bool ret = true;
   goto out;

fail:
   *new_par = *old;
   ret = false;

out:
   if (was_started)
      snd_pcm_prepare(pcm);

   return ret;
}

int
snd_pcm_hw_params(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   if (memcmp(params, &pcm->hw, sizeof(*params))) {
      WARNX("requested: rate: %u, round: %u, appbufsz: %u chan: %u", params->par.rate, params->par.round, params->par.appbufsz, (params->stream == SND_PCM_STREAM_PLAYBACK ? params->par.pchan : params->par.rchan));

      const struct sio_par old = params->par;
      if (!apply_par(pcm, &old, &params->par))
         return -1;

      WARNX("set: rate: %u, round: %u, appbufsz: %u chan: %u", params->par.rate, params->par.round, params->par.appbufsz, (params->stream == SND_PCM_STREAM_PLAYBACK ? params->par.pchan : params->par.rchan));
      pcm->hw = *params;
   }

   return snd_pcm_prepare(pcm);
}

int
snd_pcm_hw_params_current(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   *params = pcm->hw;
   return 0;
}

int
snd_pcm_hw_params_any(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   *params = pcm->hw;
   return 0;
}

int
snd_pcm_hw_params_test_access(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t _access)
{
   if (_access != SND_PCM_ACCESS_RW_INTERLEAVED)
      return -1;

   return 0;
}

int
snd_pcm_hw_params_set_access(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t _access)
{
   if (_access != SND_PCM_ACCESS_RW_INTERLEAVED)
      goto fail;

   params->access = _access;
   return 0;

fail:
   WARNX("access mode `0x%x` not supported yet", _access);
   return -1;
}

int
snd_pcm_hw_params_get_access(const snd_pcm_hw_params_t *params, snd_pcm_access_t *_access)
{
   if (_access) *_access = params->access;
   return 0;
}

int
snd_pcm_hw_params_malloc(snd_pcm_hw_params_t **ptr)
{
   return ((*ptr = calloc(1, sizeof(**ptr))) ? 0 : -1);
}

void
snd_pcm_hw_params_free(snd_pcm_hw_params_t *obj)
{
   free(obj);
}

struct _snd_pcm_format_mask {
   snd_pcm_format_t supported[ARRAY_SIZE(SUPPORTED_FORMATS)];
};

size_t
snd_pcm_format_mask_sizeof(void)
{
   return sizeof(snd_pcm_format_mask_t);
}

int
snd_pcm_format_mask_test(const snd_pcm_format_mask_t *mask, snd_pcm_format_t val)
{
   for (size_t i = 0; i < ARRAY_SIZE(mask->supported) && mask->supported[i] != SND_PCM_FORMAT_UNKNOWN; ++i) {
      if (mask->supported[i] == val)
         return true;
   }
   return false;
}

void
snd_pcm_hw_params_get_format_mask(snd_pcm_hw_params_t *params, snd_pcm_format_mask_t *mask)
{
   if (mask) memcpy(mask->supported, params->limits.supported, sizeof(mask->supported));
}

int
snd_pcm_hw_params_test_format(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t val)
{
   snd_pcm_format_mask_t mask;
   snd_pcm_hw_params_get_format_mask(params, &mask);
   return (snd_pcm_format_mask_test(&mask, val) ? 0 : -1);
}

int
snd_pcm_hw_params_set_format(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t val)
{
   const struct format_info *info;
   if (!(info = format_info_for_format(val)))
      return -1;

   params->format = val;
   WARNX("%s", info->name);
   params->needs_conversion = (snd_pcm_hw_params_test_format(pcm, params, val) != 0);

   const struct sio_par old = params->par;
   params->par.bits = info->enc.bits;
   params->par.bps = info->enc.bps;
   params->par.sig = info->enc.sig;
   params->par.le = (params->needs_conversion ? SIO_LE_NATIVE : info->enc.le);
   params->par.msb = info->enc.msb;
   return (apply_par(pcm, &old, &params->par) ? 0 : -1);
}

static int
update(snd_pcm_t *pcm, struct sio_par *par, void *curv, void *newv, const size_t size)
{
   if (!newv) return 0;
   const struct sio_par old = *par;
   memcpy(curv, newv, size);
   const bool ret = apply_par(pcm, &old, par);
   memcpy(newv, curv, size);
   return (ret ? 0 : -1);
}

int
snd_pcm_hw_params_get_channels(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   if (val) *val = (params->stream == SND_PCM_STREAM_PLAYBACK ? params->par.pchan : params->par.rchan);
   return 0;
}

int
snd_pcm_hw_params_set_channels_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val)
{
   if (val) {
      if (params->stream == SND_PCM_STREAM_PLAYBACK) {
         assert(sizeof(params->par.pchan) == sizeof(*val));
         return update(pcm, &params->par, &params->par.pchan, val, sizeof(*val));
      } else {
         assert(sizeof(params->par.rchan) == sizeof(*val));
         return update(pcm, &params->par, &params->par.rchan, val, sizeof(*val));
      }
   }
   return 0;
}

int
snd_pcm_hw_params_set_channels(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val)
{
   WARNX("%u", val);
   return snd_pcm_hw_params_set_channels_near(pcm, params, &val);
}

int
snd_pcm_hw_params_get_channels_min(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   const bool pb = (params->stream == SND_PCM_STREAM_PLAYBACK);
   if (val) *val = (pb ? params->limits.pchan[0] : params->limits.rchan[0]);
   WARNX("%u", (val ? *val : 0));
   return 0;
}

int
snd_pcm_hw_params_get_channels_max(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   const bool pb = (params->stream == SND_PCM_STREAM_PLAYBACK);
   if (val) *val = (pb ? params->limits.pchan[1] : params->limits.rchan[1]);
   WARNX("%u", (val ? *val : 0));
   return 0;
}

int
snd_pcm_hw_params_get_rate(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->par.rate;
   return 0;
}

int
snd_pcm_hw_params_get_rate_numden(const snd_pcm_hw_params_t *params, unsigned int *rate_num, unsigned int *rate_den)
{
   if (rate_num) *rate_num = params->par.rate;
   if (rate_den) *rate_den = 1;
   return 0;
}

int
snd_pcm_hw_params_set_rate_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   assert(sizeof(params->par.rate) == sizeof(*val));
   return update(pcm, &params->par, &params->par.rate, val, sizeof(*val));
}

int
snd_pcm_hw_params_set_rate(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir)
{
   return snd_pcm_hw_params_set_rate_near(pcm, params, &val, &dir);
}

int
snd_pcm_hw_params_get_rate_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->limits.rate[0];
   return 0;
}

int
snd_pcm_hw_params_get_rate_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->limits.rate[1];
   return 0;
}

int
snd_pcm_hw_params_get_buffer_size(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
{
   if (val) *val = params->par.appbufsz;
   return 0;
}

int
snd_pcm_hw_params_set_buffer_size_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
{
   if (val) {
      unsigned int newv = (*val < params->par.round ? params->par.round * 2 : *val);
      assert(sizeof(params->par.appbufsz) == sizeof(newv));
      const int ret = update(pcm, &params->par, &params->par.appbufsz, &newv, sizeof(newv));
      *val = newv;
      return ret;
   }
   return 0;
}

int
snd_pcm_hw_params_get_buffer_size_min(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
{
   if (val) *val = params->par.appbufsz;
   return 0;
}

int
snd_pcm_hw_params_get_buffer_size_max(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
{
   if (val) *val = params->par.appbufsz;
   return 0;
}

int
snd_pcm_hw_params_get_period_size(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->par.round;
   return 0;
}

int
snd_pcm_hw_params_set_period_size_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) {
      unsigned int newv = *val;
      assert(sizeof(params->par.round) == sizeof(newv));
      const int ret = update(pcm, &params->par, &params->par.round, &newv, sizeof(newv));
      *val = newv;
      return ret;
   }
   return 0;
}

int
snd_pcm_hw_params_get_period_size_min(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->par.round;
   return 0;
}

int
snd_pcm_hw_params_get_period_size_max(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->par.round;
   return 0;
}

int
snd_pcm_hw_params_get_periods(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = params->par.appbufsz / params->par.round;
   return 0;
}

int
snd_pcm_hw_params_set_periods_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) {
      unsigned int round = params->par.appbufsz / *val;
      assert(sizeof(params->par.round) == sizeof(round));
      return update(pcm, &params->par, &params->par.round, &round, sizeof(*val));
   }
   return 0;
}

int
snd_pcm_hw_params_get_periods_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = 2;
   return 0;
}

int
snd_pcm_hw_params_get_periods_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   if (val) *val = 32;
   return 0;
}

size_t
snd_pcm_sw_params_sizeof(void)
{
   return sizeof(snd_pcm_sw_params_t);
}

int
snd_pcm_sw_params_malloc(snd_pcm_sw_params_t **ptr)
{
   return ((*ptr = calloc(1, sizeof(**ptr))) ? 0 : -1);
}

void
snd_pcm_sw_params_free(snd_pcm_sw_params_t *ptr)
{
   free(ptr);
}

int
snd_pcm_sw_params_current(snd_pcm_t *pcm, snd_pcm_sw_params_t *params)
{
   *params = pcm->sw;
   return 0;
}

int
snd_pcm_set_params(snd_pcm_t *pcm, snd_pcm_format_t format, snd_pcm_access_t access, unsigned int channels, unsigned int rate, int soft_resample, unsigned int latency)
{
   snd_pcm_hw_params_t params;
   return (!snd_pcm_hw_params_any(pcm, &params) && !snd_pcm_hw_params_set_format(pcm, &params, format) &&
           !snd_pcm_hw_params_set_access(pcm, &params, access) && !snd_pcm_hw_params_set_channels(pcm, &params, channels) &&
           !snd_pcm_hw_params_set_rate(pcm, &params, rate, 0) && !snd_pcm_hw_params(pcm, &params) ? 0 : -1);
}

int
snd_pcm_get_params(snd_pcm_t *pcm, snd_pcm_uframes_t *buffer_size, snd_pcm_uframes_t *period_size)
{
   if (buffer_size) *buffer_size = pcm->hw.par.appbufsz;
   if (period_size) *period_size = pcm->hw.par.round;
   return 0;
}

snd_pcm_chmap_t*
snd_pcm_get_chmap(snd_pcm_t *pcm)
{
   const unsigned int nc = (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan);

   if (!nc || nc > 2)
      return NULL;

   snd_pcm_chmap_t *map;
   if (!(map = calloc(1, sizeof(*map) + nc))) {
      WARN1("calloc");
      return NULL;
   }

   map->channels = nc;

   if (nc == 1) {
      map->pos[0] = SND_CHMAP_MONO;
   } else if (nc == 2) {
      map->pos[0] = SND_CHMAP_FL;
      map->pos[1] = SND_CHMAP_FR;
   }

   return map;
}

struct _snd_pcm_status {
   struct timespec start, end;
   snd_pcm_sframes_t delay;
};

size_t
snd_pcm_status_sizeof(void)
{
   return sizeof(snd_pcm_status_t);
}

int
snd_pcm_status_malloc(snd_pcm_status_t **ptr)
{
   return ((*ptr = calloc(1, sizeof(**ptr))) ? 0 : -1);
}

void
snd_pcm_status_free(snd_pcm_status_t *obj)
{
   free(obj);
}

int
snd_pcm_status(snd_pcm_t *pcm, snd_pcm_status_t *status)
{
   *status = (snd_pcm_status_t){ .start = pcm->start_time };
   snd_pcm_delay(pcm, &status->delay);
   return (clock_gettime(CLOCK_MONOTONIC, &status->end) == 0 ? 0 : -1);
}

void
snd_pcm_status_get_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr)
{
   snd_htimestamp_t ats = {0};
   if ((obj->end.tv_nsec - obj->start.tv_nsec) < 0) {
      ats.tv_sec = obj->end.tv_sec - obj->start.tv_sec - 1;
      ats.tv_nsec = (uint64_t)1e9 + obj->end.tv_nsec - obj->start.tv_nsec;
   } else {
      ats.tv_sec = obj->end.tv_sec - obj->start.tv_sec;
      ats.tv_nsec = obj->end.tv_nsec - obj->start.tv_nsec;
   }
   *ptr = ats;
}

void
snd_pcm_status_get_tstamp(const snd_pcm_status_t *obj, snd_timestamp_t *ptr)
{
   snd_htimestamp_t ats;
   snd_pcm_status_get_htstamp(obj, &ats);
   *ptr = (snd_timestamp_t){ .tv_sec = ats.tv_sec, .tv_usec = ats.tv_nsec / (uint64_t)1e3 };
}

snd_pcm_sframes_t
snd_pcm_status_get_delay(const snd_pcm_status_t *obj)
{
   return obj->delay;
}
