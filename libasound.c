#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <alsa/pcm_plugin.h>
#include <alsa/pcm_extplug.h>
#include <alsa/pcm_ioplug.h>
#include <alsa/control_external.h>
#include <alsa/mixer_abst.h>
#include <alsa/use-case.h>
#include <alsa/topology.h>

#include <sndio.h>
#include <stdbool.h>
#include <assert.h>
#include <err.h>

#define WARN1(x) do { warn("asound: %s %s", __func__, x); } while (0)
#define WARN(x, ...) do { warn("asound: %s "x, __func__, ##__VA_ARGS__); } while (0)
#define WARNX1(x) do { warnx("asound: %s %s", __func__, x); } while (0)
#define WARNX(x, ...) do { warnx("asound: %s "x, __func__, ##__VA_ARGS__); } while (0)
#define ERRX(x, y, ...) do { errx(x, "asound: %s "y, __func__, ##__VA_ARGS__); } while (0)
#define ERR(x, y, ...) do { err(x, "asound: %s "y, __func__, ##__VA_ARGS__); } while (0)

#include "stubs.h"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

const char*
snd_asoundlib_version(void)
{
   return "1.1.7";
}

const char*
snd_strerror(int errnum)
{
   // Do not bother implementing this, just WARN/ERR directly in this lib
   // Letting applications show useful error messages never works out
   return "^";
}

snd_lib_error_handler_t snd_lib_error;

int snd_lib_error_set_handler(snd_lib_error_handler_t handler)
{
   snd_lib_error = handler;
   return 0;
}

struct _snd_config { char noop; } s_snd_config;
struct _snd_config *snd_config = &s_snd_config;

struct _snd_pcm_hint { char *name, *ioid; };

int
snd_device_name_hint(int card, const char *iface, void ***hints)
{
   static struct _snd_pcm_hint defaults[] = { { .name = "default", .ioid = "Output" }, { .name = "capture", .ioid = "Input" } };
   static struct _snd_pcm_hint *array[] = { &defaults[0], &defaults[1], NULL };
   *hints = (void**)array;
   return 0;
}

static char*
c_strdup(const char *str)
{
   size_t len = strlen(str);

   char *copy;
   if (!(copy = calloc(1, len + 1)))
      return NULL;

   memcpy(copy, str, len);
   return copy;
}

char*
snd_device_name_get_hint(const void *hint, const char *id)
{
   const struct _snd_pcm_hint *shint = hint;

   if (!strcmp(id, "NAME"))
      return c_strdup(shint->name);
   else if (!strcmp(id, "IOID"))
      return c_strdup(shint->ioid);

   return NULL;
}

int
snd_device_name_free_hint(void **hints)
{
   return 0;
}

struct _snd_pcm_hw_params { struct sio_par par; struct sio_cap cap; };
struct _snd_pcm_sw_params { char noop; };

struct _snd_pcm {
   struct sio_cap cap;
   struct _snd_pcm_hw_params hw, hw_requested;
   struct _snd_pcm_sw_params sw;
   struct sio_hdl *hdl;
   const char *name;
   snd_pcm_stream_t stream;
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
      case SND_PCM_NONBLOCK: return true;
      // ASYNC: SIGIO will be emitted whenever a period has been completely processed by the soundcard.
      case SND_PCM_ASYNC: errx(EXIT_FAILURE, "asound: SND_PCM_ASYNC is not supported");
   }
   return false;
}

static struct sio_hdl*
device_open(const char *name, snd_pcm_stream_t stream, int mode)
{
   const char *sndio_name = (!name || !strcmp(name, "default") ? SIO_DEVANY : name);

   struct sio_hdl *hdl;
   if (!(hdl = sio_open(sndio_name, sndio_stream(stream), sndio_mode(mode))) &&
       !(hdl = sio_open(SIO_DEVANY, sndio_stream(stream), sndio_mode(mode)))) {
      WARNX1("sio_open failed");
      return NULL;
   }

   return hdl;
}

int
snd_pcm_open(snd_pcm_t **pcm, const char *name, snd_pcm_stream_t stream, int mode)
{
   assert(pcm);

   if (!(*pcm = calloc(1, sizeof(**pcm)))) {
      WARN1("calloc");
      return -1;
   }

   if (!((*pcm)->hdl = device_open(name, stream, mode)))
      return -1;

   (*pcm)->name = name;
   return (sio_getcap((*pcm)->hdl, &(*pcm)->cap) && sio_getpar((*pcm)->hdl, &(*pcm)->hw.par) ? 0 : -1);
}

int
snd_pcm_close(snd_pcm_t *pcm)
{
   sio_close(pcm->hdl);
   free(pcm);
   return 0;
}

int
snd_pcm_nonblock(snd_pcm_t *pcm, int nonblock)
{
   sio_close(pcm->hdl);
   pcm->started = false;

   if (!(pcm->hdl = device_open(pcm->name, pcm->stream, (nonblock ? SND_PCM_NONBLOCK : false))))
      return -1;

   return snd_pcm_hw_params(pcm, &pcm->hw_requested);

}

snd_pcm_sframes_t
snd_pcm_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size)
{
   return snd_pcm_bytes_to_frames(pcm, sio_write(pcm->hdl, buffer, snd_pcm_frames_to_bytes(pcm, size)));
}

snd_pcm_sframes_t
snd_pcm_readi(snd_pcm_t *pcm, void *buffer, snd_pcm_uframes_t size)
{
   return snd_pcm_bytes_to_frames(pcm, sio_read(pcm->hdl, buffer, snd_pcm_frames_to_bytes(pcm, size)));
}

int
snd_pcm_prepare(snd_pcm_t *pcm)
{
   if (!pcm->started && sio_start(pcm->hdl))
      pcm->started = true;

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
   if (pcm->started && sio_stop(pcm->hdl))
      pcm->started = false;

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

snd_pcm_sframes_t
snd_pcm_bytes_to_frames(snd_pcm_t *pcm, ssize_t bytes)
{
   const int bpf = (pcm->hw.par.bits * pcm->hw.par.pchan) / 8;
   return bytes / bpf;
}

ssize_t
snd_pcm_frames_to_bytes(snd_pcm_t *pcm, snd_pcm_sframes_t frames)
{
   const int bpf = (pcm->hw.par.bits * pcm->hw.par.pchan) / 8;
   return frames * bpf;
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
   params->cap = pcm->cap;
   sio_initpar(&params->par);
   copy_important_params(&params->par, &pcm->hw.par);
   WARNX("rate: %u, round: %u, appbufsz: %u", params->par.rate, params->par.round, params->par.appbufsz);
   return 0;
}

int
snd_pcm_hw_params(snd_pcm_t *pcm, snd_pcm_hw_params_t *params)
{
   pcm->hw_requested = *params;

   if (memcmp(&params->par, &pcm->hw.par, sizeof(params->par))) {
      snd_pcm_drain(pcm);

      if (!sio_setpar(pcm->hdl, &pcm->hw_requested.par)) {
         WARNX1("sio_setpar failed");
         return -1;
      }

      if (!sio_getpar(pcm->hdl, &pcm->hw.par)) {
         WARNX1("sio_getpar failed");
         return -1;
      }
   }

   WARNX("rate: %u, round: %u, appbufsz: %u, bufsz: %u", pcm->hw.par.rate, pcm->hw.par.round, pcm->hw.par.appbufsz, pcm->hw.par.bufsz);
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

   return 0;

fail:
   WARNX("access mode `0x%x` not supported yet", _access);
   return -1;
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
      default:
         WARNX("unsupported format: 0x%x", format);
         return "unsupported";
   }
#undef NAME
}

static bool
pcm_format(const snd_pcm_format_t format, struct sio_par *par)
{
   switch (format) {
      case SND_PCM_FORMAT_U8:
         par->bits = 8;
         par->sig = 0;
         WARNX1("SND_PCM_FORMAT_U8");
         break;
      case SND_PCM_FORMAT_S8:
         par->bits = 8;
         par->sig = 1;
         WARNX1("SND_PCM_FORMAT_S8");
         break;
      case SND_PCM_FORMAT_S16_LE:
         par->bits = 16;
         par->sig = 1;
         par->le = 1;
         WARNX1("SND_PCM_FORMAT_S16_LE");
         break;
      case SND_PCM_FORMAT_S16_BE:
         par->bits = 16;
         par->sig = 1;
         par->le = 0;
         WARNX1("SND_PCM_FORMAT_S16_BE");
         break;
      case SND_PCM_FORMAT_U16_LE:
         par->bits = 16;
         par->sig = 0;
         par->le = 1;
         WARNX1("SND_PCM_FORMAT_U16_LE");
         break;
      case SND_PCM_FORMAT_U16_BE:
         par->bits = 16;
         par->sig = 0;
         par->le = 0;
         WARNX1("SND_PCM_FORMAT_U16_BE");
         break;
      case SND_PCM_FORMAT_S24_LE:
         par->bits = 24;
         par->sig = 1;
         par->le = 1;
         WARNX1("SND_PCM_FORMAT_S24_LE");
         break;
      case SND_PCM_FORMAT_S24_BE:
         par->bits = 24;
         par->sig = 1;
         par->le = 0;
         WARNX1("SND_PCM_FORMAT_S24_BE");
         break;
      case SND_PCM_FORMAT_U24_LE:
         par->bits = 24;
         par->sig = 0;
         par->le = 1;
         WARNX1("SND_PCM_FORMAT_U24_LE");
         break;
      case SND_PCM_FORMAT_U24_BE:
         par->bits = 24;
         par->sig = 0;
         par->le = 0;
         WARNX1("SND_PCM_FORMAT_U24_BE");
         break;
      case SND_PCM_FORMAT_S32_LE:
         par->bits = 32;
         par->sig = 1;
         par->le = 1;
         WARNX1("SND_PCM_FORMAT_S32_LE");
         break;
      case SND_PCM_FORMAT_S32_BE:
         par->bits = 32;
         par->sig = 1;
         par->le = 0;
         WARNX1("SND_PCM_FORMAT_S32_BE");
         break;
      case SND_PCM_FORMAT_U32_LE:
         par->bits = 32;
         par->sig = 0;
         par->le = 1;
         WARNX1("SND_PCM_FORMAT_U32_LE");
         break;
      case SND_PCM_FORMAT_U32_BE:
         par->bits = 32;
         par->sig = 0;
         par->le = 0;
         WARNX1("SND_PCM_FORMAT_U32_BE");
         break;
      default:
         WARNX("unsupported format: 0x%x", format);
         return false;
   }
   return true;
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
         SND_PCM_FORMAT_U32_BE
   };
   static snd_pcm_format_mask_t def_mask = { .fmts = def_fmts, .nmemb = ARRAY_SIZE(def_fmts) };
   *mask = def_mask;
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
snd_pcm_hw_params_set_format(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t val)
{
   // FIXME: prob should check hw caps
   return (pcm_format(val, &params->par) ? 0 : -1);
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
   // FIXME: need to store stream info in params
   if (val) *val = params->par.pchan;
   return 0;
}

int
snd_pcm_hw_params_set_channels(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val)
{
   if (pcm->stream == SND_PCM_STREAM_PLAYBACK) {
      assert(sizeof(params->par.pchan) == sizeof(val));
      return update(pcm, &params->par, &params->par.pchan, &val, sizeof(val));
   } else {
      assert(sizeof(params->par.rchan) == sizeof(val));
      return update(pcm, &params->par, &params->par.rchan, &val, sizeof(val));
   }
}

int
snd_pcm_hw_params_get_channels_min(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   // FIXME: need to store stream info in params
   unsigned int min = (unsigned int)~0;
   for (int i = 0; i < SIO_NCHAN; ++i) {
      if (!(params->cap.confs[0].pchan & (1 << i)))
         continue;
      min = (params->cap.pchan[i] < min ? params->cap.pchan[i] : min);
   }
   if (val) *val = min;
   return 0;
}

int
snd_pcm_hw_params_get_channels_max(const snd_pcm_hw_params_t *params, unsigned int *val)
{
   // FIXME: need to store stream info in params
   unsigned int max = 0;
   for (int i = 0; i < SIO_NCHAN; ++i) {
      if (!(params->cap.confs[0].pchan & (1 << i)))
         continue;
      max = (params->cap.pchan[i] > max ? params->cap.pchan[i] : max);
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
snd_pcm_hw_params_set_rate(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir)
{
   assert(sizeof(params->par.rate) == sizeof(val));
   return update(pcm, &params->par, &params->par.rate, &val, sizeof(val));
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
snd_pcm_hw_params_set_rate_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
{
   if (dir) *dir = 0;
   assert(sizeof(params->par.rate) == sizeof(*val));
   return update(pcm, &params->par, &params->par.rate, val, sizeof(*val));
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
      unsigned int newv = *val;
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
   assert(sizeof(params->par.round) == sizeof(*val));
   return update(pcm, &params->par, &params->par.round, val, sizeof(*val));
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
snd_pcm_sw_params_current(snd_pcm_t *pcm, snd_pcm_sw_params_t *params)
{
   *params = pcm->sw;
   return 0;
}

#include "symversioning-hell.h"
