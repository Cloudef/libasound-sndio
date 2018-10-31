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

struct _snd_config { char noop; } s_snd_config;
struct _snd_config *snd_config = &s_snd_config;

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

int
snd_card_load(int card)
{
   return 0;
}

int
snd_card_next(int *card)
{
   if (card) {
      *card = (*card == -1 ? 0 : -1);
      return 0;
   }

   return -1;
}

int
snd_card_get_index(const char *name)
{
   if (!strcmp(name, "default"))
      return 0;

   return -1;
}

int
snd_card_get_name(int card, char **name)
{
   if (name) *name = "default";
   return 0;
}

int snd_card_get_longname(int card, char **name)
{
   if (name) *name = "default";
   return 0;
}

struct device_name_hint { char *name, *ioid; };

int
snd_device_name_hint(int card, const char *iface, void ***hints)
{
   static struct device_name_hint defaults[] = { { .name = "default", .ioid = "Output" }, { .name = "capture", .ioid = "Input" } };
   static struct device_name_hint *array[] = { &defaults[0], &defaults[1], NULL };
   *hints = (void**)array;
   return 0;
}

char*
snd_device_name_get_hint(const void *hint, const char *id)
{
   const struct device_name_hint *shint = hint;

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

struct _snd_ctl {
   char noop;
};

int
snd_ctl_open(snd_ctl_t **ctl, const char *name, int mode)
{
   if (!(*ctl = calloc(1, sizeof(**ctl)))) {
      WARNX1("calloc");
      return -1;
   }

   return 0;
}

int
snd_ctl_close(snd_ctl_t *ctl)
{
   free(ctl);
   return 0;
}

struct _snd_ctl_card_info {
   const char *name;
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
   info->name = "sndio";
   return 0;
}

const char*
snd_ctl_card_info_get_name(const snd_ctl_card_info_t *obj)
{
   return obj->name;
}

const char*
snd_ctl_card_info_get_mixername(const snd_ctl_card_info_t *obj)
{
   return obj->name;
}
