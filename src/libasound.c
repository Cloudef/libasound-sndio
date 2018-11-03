#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <alsa/pcm_plugin.h>
#include <alsa/pcm_extplug.h>
#include <alsa/pcm_ioplug.h>
#include <alsa/control_external.h>
#include <alsa/mixer_abst.h>
#include <alsa/use-case.h>
#include <alsa/topology.h>

#include "util/util.h"
#include "stubs.h"
#include "symversioning-hell.h"

enum {
   CARD_NONE = -1,
   CARD_DEFAULT,
};

static const char *CARD_NAMES[] = {
   "sndio", // CARD_DEFAULT // hw:0
};

enum {
   PCM_NONE = -1,
   PCM_PLAYBACK,
   PCM_CAPTURE
};

static const struct {
   const char *name;
   snd_pcm_stream_t stream;
} PCMS[] = {
   { .name = "playback", .stream = SND_PCM_STREAM_PLAYBACK }, // PCM_PLAYBACK // hw:?,0
   { .name = "capture", .stream = SND_PCM_STREAM_CAPTURE },  // PCM_CAPTURE // hw:?,1
};

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
   return "set env variable `LIBASOUND_DEBUG` to 1 for more information";
}

snd_lib_error_handler_t snd_lib_error;

int snd_lib_error_set_handler(snd_lib_error_handler_t handler)
{
   snd_lib_error = handler;
   return 0;
}

int
snd_card_load(int card)
{
   return 0;
}

int
snd_card_next(int *card)
{
   if (card) {
      *card = (*card + 1 >= (int)ARRAY_SIZE(CARD_NAMES) ? CARD_NONE : *card + 1);
      return 0;
   }

   return -1;
}

int
snd_card_get_index(const char *name)
{
   if (!strcmp(name, "default") || !strcmp(name, "hw:0"))
      return CARD_DEFAULT;

   for (unsigned int i = 0; i < ARRAY_SIZE(CARD_NAMES); ++i) {
      if (!strcmp(name, CARD_NAMES[i]))
         return i;
   }

   return -1;
}

int
snd_card_get_name(int card, char **name)
{
   if (card < 0 || (unsigned int)card >= ARRAY_SIZE(CARD_NAMES))
      return -1;

   if (name) *name = c_strdup(CARD_NAMES[card]);
   return 0;
}

int snd_card_get_longname(int card, char **name)
{
   return snd_card_get_name(card, name);
}

struct device_name_hint { int id; };

int
snd_device_name_hint(int card, const char *iface, void ***hints)
{
   static struct device_name_hint defaults[] = { {PCM_PLAYBACK}, {PCM_CAPTURE} };
   static struct device_name_hint *array[] = { &defaults[0], &defaults[1], NULL };
   *hints = (void**)array;
   return 0;
}

char*
snd_device_name_get_hint(const void *hint, const char *id)
{
   const struct device_name_hint *shint = hint;

   if (shint->id < 0 || (unsigned int)shint->id >= ARRAY_SIZE(PCMS))
      return NULL;

   if (!strcmp(id, "NAME"))
      return c_strdup(PCMS[shint->id].name);
   else if (!strcmp(id, "IOID"))
      return c_strdup((PCMS[shint->id].stream == SND_PCM_STREAM_PLAYBACK ? "Output" : "Input"));

   return NULL;
}

int
snd_device_name_free_hint(void **hints)
{
   return 0;
}

struct _snd_ctl {
   int id;
};

int
snd_ctl_open(snd_ctl_t **ctl, const char *name, int mode)
{
   int id;
   if ((id = snd_card_get_index((name ? name : "default"))) < 0)
      return -1;

   if (!(*ctl = calloc(1, sizeof(**ctl)))) {
      WARNX1("calloc");
      return -1;
   }

   (*ctl)->id = id;
   return 0;
}

int
snd_ctl_close(snd_ctl_t *ctl)
{
   free(ctl);
   return 0;
}

snd_ctl_t*
snd_hctl_ctl(snd_hctl_t *hctl)
{
   snd_ctl_t *ctl = NULL;
   snd_ctl_open(&ctl, NULL, 0);
   return ctl;
}

int
snd_ctl_pcm_next_device(snd_ctl_t *ctl, int *device)
{
   if (device) {
      *device = (*device + 1 >= (int)ARRAY_SIZE(PCMS) ? PCM_NONE : *device + 1);
      return 0;
   }

   return -1;
}

struct _snd_pcm_info {
   int card, id, subdevice;
   snd_pcm_stream_t stream;
};

size_t
snd_pcm_info_sizeof(void)
{
   return sizeof(snd_pcm_info_t);
}

int
snd_pcm_info_malloc(snd_pcm_info_t **ptr)
{
   if (!(*ptr = calloc(1, sizeof(**ptr)))) {
      WARNX1("calloc failed");
      return -1;
   }

   return 0;
}

void
snd_pcm_info_free(snd_pcm_info_t *obj)
{
   free(obj);
}

void
snd_pcm_info_set_device(snd_pcm_info_t *obj, unsigned int val)
{
   obj->id = val;
}

void
snd_pcm_info_set_stream(snd_pcm_info_t *obj, snd_pcm_stream_t val)
{
   obj->stream = val;
}

void
snd_pcm_info_set_subdevice(snd_pcm_info_t *obj, unsigned int val)
{
   obj->subdevice = val;
}

int
snd_ctl_pcm_info(snd_ctl_t *ctl, snd_pcm_info_t *info)
{
   if (info->id < 0 || (unsigned int)info->id >= ARRAY_SIZE(PCMS) || info->subdevice != 0)
      return -1;

   info->card = ctl->id;
   return (PCMS[info->id].stream == info->stream ? 0 : -ENOENT);
}

const char*
snd_pcm_info_get_name(const snd_pcm_info_t *obj)
{
   assert(obj->id >= 0 && (unsigned int)obj->id < ARRAY_SIZE(PCMS));
   return PCMS[obj->id].name;
}

unsigned int
snd_pcm_info_get_device(const snd_pcm_info_t *obj)
{
   return obj->id;
}

unsigned int
snd_pcm_info_get_subdevice(const snd_pcm_info_t *obj)
{
   return 0;
}

snd_pcm_stream_t
snd_pcm_info_get_stream(const snd_pcm_info_t *obj)
{
   return obj->stream;
}

int snd_pcm_info_get_card(const snd_pcm_info_t *obj)
{
   return obj->card;
}

struct _snd_ctl_card_info {
   int id;
};

size_t
snd_ctl_card_info_sizeof(void)
{
   return sizeof(snd_ctl_card_info_t);
}

int
snd_ctl_card_info_malloc(snd_ctl_card_info_t **ptr)
{
   if (!(*ptr = calloc(1, sizeof(**ptr))))
      return -1;

   return 0;
}

void
snd_ctl_card_info_free(snd_ctl_card_info_t *obj)
{
   free(obj);
}

int
snd_ctl_card_info(snd_ctl_t *ctl, snd_ctl_card_info_t *info)
{
   *info = (snd_ctl_card_info_t){ ctl->id };
   return 0;
}

const char*
snd_ctl_card_info_get_name(const snd_ctl_card_info_t *obj)
{
   assert(obj->id >= 0 && (unsigned int)obj->id < ARRAY_SIZE(CARD_NAMES));
   return CARD_NAMES[obj->id];
}

const char*
snd_ctl_card_info_get_id(const snd_ctl_card_info_t *obj)
{
   return snd_ctl_card_info_get_name(obj);
}

const char*
snd_ctl_card_info_get_driver(const snd_ctl_card_info_t *obj)
{
   return snd_ctl_card_info_get_name(obj);
}

const char*
snd_ctl_card_info_get_longname(const snd_ctl_card_info_t *obj)
{
   return snd_ctl_card_info_get_name(obj);
}

const char*
snd_ctl_card_info_get_mixername(const snd_ctl_card_info_t *obj)
{
   return snd_ctl_card_info_get_name(obj);
}

const char*
snd_ctl_card_info_get_components(const snd_ctl_card_info_t *obj)
{
   return snd_ctl_card_info_get_name(obj);
}

int
snd_seq_query_next_port(snd_seq_t *handle, snd_seq_port_info_t *info)
{
   return -1;
}

int
snd_seq_query_next_client(snd_seq_t *handle, snd_seq_client_info_t *info)
{
   return -1;
}

// snd_config insanity is needed for portaudio (e.g. used by audacity) since it has buggy code

struct _snd_config {
   const char *path;

   union {
      const char *id, *str;
   } v;

   enum {
      TYPE_NONE,
      TYPE_ID,
      TYPE_STR
   } type;

   snd_config_t *next;
} s_snd_config;

snd_config_t *snd_config = &s_snd_config;

int
snd_config_search(snd_config_t *config, const char *key, snd_config_t **result)
{
   char path[255];
   const char *cp = (config->path ? config->path : ".");
   snprintf(path, sizeof(path), "%s/%s", cp, key);

   if (!strcmp(path, "./pcm")) {
      static snd_config_t res = { .path = "./pcm", .v.id = "default", .type = TYPE_ID };
      if (result) *result = &res;
      return 0;
   } else if (!strcmp(path, "./pcm/type")) {
      static snd_config_t res = { .path = "./pcm/type", .v.str = "default", .type = TYPE_STR };
      if (result) *result = &res;
      return 0;
   }

   return -1;
}

snd_config_iterator_t
snd_config_iterator_first(const snd_config_t *node)
{
   return (void*)node;
}

snd_config_iterator_t
snd_config_iterator_next(const snd_config_iterator_t iterator)
{
   const snd_config_t *cfg = (void*)iterator;
   return (cfg ? (void*)cfg->next : NULL);
}

snd_config_iterator_t
snd_config_iterator_end(const snd_config_t *node)
{
   return NULL;
}

snd_config_t*
snd_config_iterator_entry(const snd_config_iterator_t iterator)
{
   return (void*)iterator;
}

int
snd_config_get_id(const snd_config_t *config, const char **value)
{
   if (config->type != TYPE_ID)
      return -1;

   if (value) *value = config->v.id;
   return 0;
}

int
snd_config_get_string(const snd_config_t *config, const char **value)
{
   if (config->type != TYPE_STR)
      return -1;

   if (value) *value = config->v.str;
   return 0;
}
