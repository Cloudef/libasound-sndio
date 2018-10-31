#include <alsa/asoundlib.h>
#include <sndio.h>
#include <poll.h>
#include <stdbool.h>
#include <assert.h>
#include "util/dsp.h"
#include "util/util.h"

struct _snd_pcm_hw_params {
   struct sio_cap cap;
   struct sio_par par;
   snd_pcm_format_t alsa_format;
   snd_pcm_access_t access;
   snd_pcm_stream_t stream;
   bool needs_conversion; // for unsupported formats
};

struct _snd_pcm_sw_params { char noop; };

struct _snd_pcm {
   struct _snd_pcm_hw_params hw, hw_requested;
   struct _snd_pcm_sw_params sw;
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

   sio_onmove(hdl, onmove, pcm);
   pcm->mode = mode;
   pcm->hw.stream = stream;
   return hdl;
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

   sio_initpar(&(*pcm)->hw_requested.par);
   (*pcm)->name = (name ? name : "default");
   return (sio_getcap((*pcm)->hdl, &(*pcm)->hw.cap) && sio_getpar((*pcm)->hdl, &(*pcm)->hw.par) ? 0 : -1);

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

   return snd_pcm_hw_params(pcm, &pcm->hw_requested);
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

static size_t
io_do(snd_pcm_t *pcm, void *buffer, const size_t frames, size_t (*io)(struct sio_hdl*, void*, size_t))
{
   if (pcm->hw.needs_conversion) {
      struct aparams params = {
         .bps = pcm->hw.par.bps,
         .bits = pcm->hw.par.bits,
         .le = pcm->hw.par.le,
         .sig = pcm->hw.par.sig,
         .msb = pcm->hw.par.msb
      };

      struct conv dec, enc;
      dec_init(&dec, &params, (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan));
      enc_init(&enc, &params, (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan));

      size_t total_frames = frames, io_bytes = 0;
      unsigned char decoded[4096], encoded[sizeof(decoded)];
      const size_t max_frames = snd_pcm_bytes_to_frames(pcm, sizeof(decoded));
      for (unsigned char *p = buffer; total_frames > 0;) {
         const int todo_frames = (total_frames > max_frames ? max_frames : total_frames);
         total_frames -= todo_frames;

         // sadly can't function pointer here as some formats may need different parameters for decoder
         if (pcm->hw.alsa_format == SND_PCM_FORMAT_FLOAT_LE || pcm->hw.alsa_format == SND_PCM_FORMAT_FLOAT_BE) {
            dec_do_float(&dec, p, decoded, todo_frames);
         } else {
            dec_do(&dec, p, decoded, todo_frames);
         }

         enc_do(&enc, decoded, encoded, todo_frames);

         const size_t todo_bytes = snd_pcm_frames_to_bytes(pcm, todo_frames);
         io_bytes += io(pcm->hdl, encoded, todo_bytes);
         p += todo_bytes;
      }

      return io_bytes;
   }

   return io(pcm->hdl, buffer, snd_pcm_frames_to_bytes(pcm, frames));
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

snd_pcm_sframes_t
snd_pcm_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size)
{
   if (pcm->hw.stream != SND_PCM_STREAM_PLAYBACK) {
      WARNX1("trying to write to capture stream :/");
      return 0;
   }

   const snd_pcm_sframes_t ret = snd_pcm_bytes_to_frames(pcm, io_do(pcm, (void*)buffer, size, (size_t(*)(struct sio_hdl*, void*, size_t))sio_write));
   pcm->written += ret;
   pcm->avail -= ret;
   return ret;
}

snd_pcm_sframes_t
snd_pcm_readi(snd_pcm_t *pcm, void *buffer, snd_pcm_uframes_t size)
{
   if (pcm->hw.stream != SND_PCM_STREAM_CAPTURE) {
      WARNX1("trying to read from playback stream :/");
      return 0;
   }

   const snd_pcm_sframes_t ret = snd_pcm_bytes_to_frames(pcm, io_do(pcm, buffer, size, sio_read));
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

static void
copy_important_params(struct sio_par *dst, const struct sio_par *src)
{
   assert(dst && src);
   dst->rate = src->rate;
   dst->pchan = src->pchan;
   dst->rchan = src->rchan;
   dst->appbufsz = src->appbufsz;
   dst->round = src->round;
}

int
snd_pcm_hw_params_any(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   params->cap = pcm->hw.cap;
   params->stream = pcm->hw.stream;
   sio_initpar(&params->par);
   copy_important_params(&params->par, &pcm->hw.par);
   WARNX("rate: %u, round: %u, appbufsz: %u chan: %u", params->par.rate, params->par.round, params->par.appbufsz, (params->stream == SND_PCM_STREAM_PLAYBACK ? params->par.pchan : params->par.rchan));
   return 0;
}

int
snd_pcm_hw_params(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   if (memcmp(params, &pcm->hw, sizeof(*params))) {
      snd_pcm_drain(pcm);

      pcm->hw_requested = *params;
      if (!sio_setpar(pcm->hdl, &params->par)) {
         WARNX1("sio_setpar failed");
         return -1;
      }

      pcm->hw = *params;
      if (!sio_getpar(pcm->hdl, &pcm->hw.par)) {
         WARNX1("sio_getpar failed");
         return -1;
      }
   }

   WARNX("rate: %u, round: %u, appbufsz: %u, bufsz: %u, chan: %u", pcm->hw.par.rate, pcm->hw.par.round, pcm->hw.par.appbufsz, pcm->hw.par.bufsz, (pcm->hw.stream == SND_PCM_STREAM_PLAYBACK ? pcm->hw.par.pchan : pcm->hw.par.rchan));
   return snd_pcm_prepare(pcm);
}

int
snd_pcm_hw_params_current(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   *params = pcm->hw;
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

const char*
snd_pcm_format_name(const snd_pcm_format_t format)
{
#define NAME(x) case x: return #x
   switch (format) {
      NAME(SND_PCM_FORMAT_U8);
      NAME(SND_PCM_FORMAT_S8);
      NAME(SND_PCM_FORMAT_S16_LE);
      NAME(SND_PCM_FORMAT_S16_BE);
      NAME(SND_PCM_FORMAT_U16_LE);
      NAME(SND_PCM_FORMAT_U16_BE);
      NAME(SND_PCM_FORMAT_S24_LE);
      NAME(SND_PCM_FORMAT_S24_BE);
      NAME(SND_PCM_FORMAT_U24_LE);
      NAME(SND_PCM_FORMAT_U24_BE);
      NAME(SND_PCM_FORMAT_S32_LE);
      NAME(SND_PCM_FORMAT_S32_BE);
      NAME(SND_PCM_FORMAT_U32_LE);
      NAME(SND_PCM_FORMAT_U32_BE);
      NAME(SND_PCM_FORMAT_FLOAT_LE);
      NAME(SND_PCM_FORMAT_FLOAT_BE);
      default:
         WARNX("unsupported format: 0x%x", format);
         return "unsupported";
   }
#undef NAME
}

static bool
pcm_format(const snd_pcm_format_t format, struct sio_par *par, bool *out_needs_conversion)
{
   switch (format) {
      case SND_PCM_FORMAT_U8:
         par->bits = 8;
         par->sig = 0;
         break;
      case SND_PCM_FORMAT_S8:
         par->bits = 8;
         par->sig = 1;
         break;
      case SND_PCM_FORMAT_S16_LE:
         par->bits = 16;
         par->sig = 1;
         par->le = 1;
         break;
      case SND_PCM_FORMAT_S16_BE:
         par->bits = 16;
         par->sig = 1;
         par->le = 0;
         break;
      case SND_PCM_FORMAT_U16_LE:
         par->bits = 16;
         par->sig = 0;
         par->le = 1;
         break;
      case SND_PCM_FORMAT_U16_BE:
         par->bits = 16;
         par->sig = 0;
         par->le = 0;
         break;
      case SND_PCM_FORMAT_S24_LE:
         par->bits = 24;
         par->sig = 1;
         par->le = 1;
         break;
      case SND_PCM_FORMAT_S24_BE:
         par->bits = 24;
         par->sig = 1;
         par->le = 0;
         break;
      case SND_PCM_FORMAT_U24_LE:
         par->bits = 24;
         par->sig = 0;
         par->le = 1;
         break;
      case SND_PCM_FORMAT_U24_BE:
         par->bits = 24;
         par->sig = 0;
         par->le = 0;
         break;
      case SND_PCM_FORMAT_FLOAT_LE:
         *out_needs_conversion = true;
         /* fallthrough */
      case SND_PCM_FORMAT_S32_LE:
         par->bits = 32;
         par->sig = 1;
         par->le = 1;
         break;
      case SND_PCM_FORMAT_FLOAT_BE:
         *out_needs_conversion = true;
         /* fallthrough */
      case SND_PCM_FORMAT_S32_BE:
         par->bits = 32;
         par->sig = 1;
         par->le = 0;
         break;
      case SND_PCM_FORMAT_U32_LE:
         par->bits = 32;
         par->sig = 0;
         par->le = 1;
         break;
      case SND_PCM_FORMAT_U32_BE:
         par->bits = 32;
         par->sig = 0;
         par->le = 0;
         break;
      default:
         WARNX("unsupported format: 0x%x", format);
         return false;
   }
   return true;
}

int snd_pcm_format_width(snd_pcm_format_t format)
{
   struct sio_par par = {0};
   pcm_format(format, &par, (bool[]){false});
   return par.bits;
}

int snd_pcm_format_physical_width(snd_pcm_format_t format)
{
   return snd_pcm_format_width(format);
}

struct _snd_pcm_format_mask {
   snd_pcm_format_t *fmts;
   uint8_t nmemb;
};

size_t
snd_pcm_format_mask_sizeof(void)
{
   return sizeof(snd_pcm_format_mask_t);
}

int
snd_pcm_hw_params_malloc(snd_pcm_hw_params_t **ptr)
{
   // OpenAL-soft uses this :(
   *ptr = calloc(1, sizeof(**ptr));
   return (*ptr ? 0 : -1);
}

void
snd_pcm_hw_params_free(snd_pcm_hw_params_t *obj)
{
   free(obj);
}

void
snd_pcm_hw_params_get_format_mask(snd_pcm_hw_params_t *params, snd_pcm_format_mask_t *mask)
{
   static snd_pcm_format_t def_fmts[] = {
         SND_PCM_FORMAT_U8,
         SND_PCM_FORMAT_S8,
         SND_PCM_FORMAT_S16_LE,
         SND_PCM_FORMAT_S16_BE,
         SND_PCM_FORMAT_U16_LE,
         SND_PCM_FORMAT_U16_BE,
         SND_PCM_FORMAT_S24_LE,
         SND_PCM_FORMAT_S24_BE,
         SND_PCM_FORMAT_U24_LE,
         SND_PCM_FORMAT_U24_BE,
         SND_PCM_FORMAT_S32_LE,
         SND_PCM_FORMAT_S32_BE,
         SND_PCM_FORMAT_U32_LE,
         SND_PCM_FORMAT_U32_BE,
         SND_PCM_FORMAT_FLOAT_LE,
         SND_PCM_FORMAT_FLOAT_BE
   };
   static snd_pcm_format_mask_t def_mask = { .fmts = def_fmts, .nmemb = ARRAY_SIZE(def_fmts) };
   if (mask) *mask = def_mask;
}

int
snd_pcm_format_mask_test(const snd_pcm_format_mask_t *mask, snd_pcm_format_t val)
{
   for (uint8_t i = 0; i < mask->nmemb; ++i) {
      if (mask->fmts[i] != val)
         continue;

      return true;
   }
   return false;
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
   // FIXME: prob should check hw caps
   if (!pcm_format(val, &params->par, &params->needs_conversion))
      return -1;

   WARNX1(snd_pcm_format_name(val));
   params->alsa_format = val;
   params->par.bps = SIO_BPS(params->par.bits);
   return 0;
}

static int
update(snd_pcm_t *pcm, struct sio_par *par, void *curv, void *newv, const size_t size)
{
   if (!newv)
      return 0;

   struct sio_par old = *par;
   memcpy(curv, newv, size);
   const bool was_started = pcm->started;

   if (was_started)
      snd_pcm_drain(pcm);

   if (!sio_setpar(pcm->hdl, par)) {
      WARNX1("sio_setpar failed");
      *par = old;
      return 0;
   }

   struct sio_par hpar;
   if (sio_getpar(pcm->hdl, &hpar)) {
      copy_important_params(par, &hpar);
   } else {
      WARNX1("sio_getpar failed");
   }

   memcpy(newv, curv, size);

   if (was_started)
      snd_pcm_prepare(pcm);

   return 0;
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
   return snd_pcm_hw_params_set_channels_near(pcm, params, &val);
}

int
snd_pcm_hw_params_get_channels_min(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   const bool pb = (params->stream == SND_PCM_STREAM_PLAYBACK);
   unsigned int min = (unsigned int)~0;
   for (int i = 0; i < SIO_NCHAN; ++i) {
      if (!((pb ? params->cap.confs[0].pchan : params->cap.confs[0].rchan) & (1 << i)))
         continue;
      min = ((pb ? params->cap.pchan[i] : params->cap.rchan[i]) < min ? (pb ? params->cap.pchan[i] : params->cap.rchan[i]) : min);
   }
   if (val) *val = min;
   return 0;
}

int
snd_pcm_hw_params_get_channels_max(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   const bool pb = (params->stream == SND_PCM_STREAM_PLAYBACK);
   unsigned int max = 0;
   for (int i = 0; i < SIO_NCHAN; ++i) {
      if (!((pb ? params->cap.confs[0].pchan : params->cap.confs[0].rchan) & (1 << i)))
         continue;
      max = ((pb ? params->cap.pchan[i] : params->cap.rchan[i]) > max ? (pb ? params->cap.pchan[i] : params->cap.rchan[i]) : max);
   }
   if (val) *val = max;
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
   unsigned int min = (unsigned int)~0;
   for (int i = 0; i < SIO_NRATE; ++i) {
      if (!(params->cap.confs[0].rate & (1 << i)))
         continue;
      min = (params->cap.rate[i] < min ? params->cap.rate[i] : min);
   }
   if (dir) *dir = 0;
   if (val) *val = min;
   return 0;
}

int
snd_pcm_hw_params_get_rate_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   unsigned int max = 0;
   for (int i = 0; i < SIO_NRATE; ++i) {
      if (!(params->cap.confs[0].rate & (1 << i)))
         continue;
      max = (params->cap.rate[i] > max ? params->cap.rate[i] : max);
   }
   if (dir) *dir = 0;
   if (val) *val = max;
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

size_t
snd_pcm_sw_params_sizeof(void)
{
   return sizeof(snd_pcm_sw_params_t);
}

int
snd_pcm_sw_params_malloc(snd_pcm_sw_params_t **ptr)
{
   // OpenAL-soft uses this :(
   *ptr = calloc(1, sizeof(**ptr));
   return (*ptr ? 0 : -1);
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

   snd_pcm_chmap_t *map;
   if (!(map = calloc(1, sizeof(*map) + nc)))
      return NULL;

   map->channels = nc;

   if (nc == 1) {
      map->pos[0] = SND_CHMAP_MONO;
   } else if (nc == 2) {
      map->pos[0] = SND_CHMAP_FL;
      map->pos[1] = SND_CHMAP_FR;
   }

   return map;
}
