#include <alsa/asoundlib.h>
#include <sndio.h>
#include <stdbool.h>
#include <stdio.h>
#include "util/sysex.h"
#include "util/util.h"

struct _snd_mixer_elem {
   snd_mixer_elem_t *next;
   snd_mixer_t *mixer;
   char name[SYSEX_NAMELEN];
   unsigned int index, vol, muted_vol;
};

struct _snd_mixer {
   struct mio_hdl *hdl;
   snd_mixer_elem_t *controls;
};

#define MIXER_MAX_CHANNELS 16

static bool
onsysex(unsigned char *buf, unsigned len, snd_mixer_elem_t controls[MIXER_MAX_CHANNELS + 1])
{
   if (len < SYSEX_SIZE(empty))
      return false;

   union {
      struct sysex x;
      unsigned char buf[sizeof(struct sysex)];
   } u;

   memcpy(u.buf, buf, len);

   if (u.x.type == SYSEX_TYPE_RT && u.x.id0 == SYSEX_CONTROL && u.x.id1 == SYSEX_MASTER) {
      if (len == SYSEX_SIZE(master)) {
         controls[0].index = 0;
         controls[0].vol = u.x.u.master.coarse;
         snprintf(controls[0].name, sizeof(controls[0].name), "master");
      }
      return false;
   }

   if (u.x.type != SYSEX_TYPE_EDU || u.x.id0 != SYSEX_AUCAT)
      return false;

   switch (u.x.id1) {
      case SYSEX_AUCAT_MIXINFO: {
         unsigned cn = u.x.u.mixinfo.chan;
         if (cn >= MIXER_MAX_CHANNELS || !memchr(u.x.u.mixinfo.name, '\0', SYSEX_NAMELEN))
            return false;

         controls[cn + 1].index = cn + 1;
         snprintf(controls[cn + 1].name, sizeof(controls[cn + 1].name), "%s", u.x.u.mixinfo.name);
         break;
      }

      case SYSEX_AUCAT_DUMPEND:
         return true;
   }

   return false;
}

static void
oncommon(unsigned char *buf, unsigned len, snd_mixer_elem_t controls[MIXER_MAX_CHANNELS + 1])
{
#define MIDI_CMDMASK 0xf0
#define MIDI_CTL 0xb0
#define MIDI_CTLVOL 7
   if ((buf[0] & MIDI_CMDMASK) != MIDI_CTL || buf[1] != MIDI_CTLVOL)
      return;

#define MIDI_CHANMASK 0x0f
   unsigned cn = (buf[0] & MIDI_CHANMASK);
   if (cn >= MIXER_MAX_CHANNELS)
      return;

   controls[cn + 1].vol = buf[2];
}

static void
get_controls(snd_mixer_t *mixer)
{
   const unsigned char dumpreq[] = {
      SYSEX_START,
      SYSEX_TYPE_EDU,
      0,
      SYSEX_AUCAT,
      SYSEX_AUCAT_DUMPREQ,
      SYSEX_END,
   };

   static snd_mixer_elem_t controls[MIXER_MAX_CHANNELS + 1];

   unsigned char buf[0x100];
   mio_write(mixer->hdl, dumpreq, sizeof(dumpreq));
   for (int ready = 0; !ready;) {
      size_t size;
      if (!(size = mio_read(mixer->hdl, buf, sizeof(buf)))) {
         WARNX1("mio_read failed");
         return;
      }

      static unsigned voice_len[] = { 3, 3, 3, 3, 2, 2, 3 };
      static unsigned common_len[] = { 0, 2, 3, 2, 0, 0, 1, 1 };

      unsigned char mmsg[0x100];
      unsigned int mst = 0, midx = 0, mlen = 0;
      for (unsigned char *p = buf; size > 0; --size, ++p) {
         if (*p >= 0xf8) {
            /* clock events */
         } else if (*p >= 0xf0) {
            if (mst == SYSEX_START && *p == SYSEX_END && midx < sizeof(mmsg)) {
               mmsg[midx++] = *p;
               ready = onsysex(mmsg, midx, controls);
               continue;
            }

            mmsg[0] = *p;
            mlen = common_len[*p & 7];
            mst = *p;
            midx = 1;
         } else if (*p >= 0x80) {
            mmsg[0] = *p;
            mlen = voice_len[(*p >> 4) & 7];
            mst = *p;
            midx = 1;
         } else if (mst) {
            if (midx == sizeof(mmsg))
               continue;

            if (midx == 0)
               mmsg[midx++] = mst;

            mmsg[midx++] = *p;

            if (midx == mlen) {
               oncommon(mmsg, midx, controls);
               midx = 0;
            }
         }
      }
   }

   mixer->controls = NULL;
   snd_mixer_elem_t **tail = &mixer->controls;
   for (size_t i = 0; i < ARRAY_SIZE(controls); ++i) {
      if (!controls[i].name[0])
         continue;

      controls[i].next = NULL;
      controls[i].mixer = mixer;
      *tail = &controls[i];
      tail = &controls[i].next;
   }
}

static void
setvol(snd_mixer_t *mixer, unsigned cn, unsigned vol)
{
   if (!cn) {
      struct sysex msg = {
         .start = SYSEX_START,
         .type = SYSEX_TYPE_RT,
         .id0 = SYSEX_CONTROL,
         .id1 = SYSEX_MASTER,
         .u.master.fine = 0,
         .u.master.coarse = vol,
         .u.master.end = SYSEX_END,
      };
      mio_write(mixer->hdl, &msg, SYSEX_SIZE(master));
   } else {
      unsigned char msg[3] = { MIDI_CTL | (cn - 1), MIDI_CTLVOL, vol };
      mio_write(mixer->hdl, msg, sizeof(msg));
   }
}

int
snd_mixer_open(snd_mixer_t **mixer, int mode)
{
   if (!(*mixer = calloc(1, sizeof(**mixer)))) {
      WARN1("calloc");
      return -1;
   }

   if (!((*mixer)->hdl = mio_open("snd/0", MIO_OUT | MIO_IN, false))) {
      WARNX1("mio_open failed");
      goto fail;
   }

   get_controls(*mixer);
   return 0;

fail:
   free(*mixer);
   return -1;
}

int
snd_mixer_close(snd_mixer_t *mixer)
{
   mio_close(mixer->hdl);
   free(mixer);
   return 0;
}

int
snd_mixer_poll_descriptors_count(snd_mixer_t *mixer)
{
   return mio_nfds(mixer->hdl);
}

int
snd_mixer_poll_descriptors(snd_mixer_t *mixer, struct pollfd *pfds, unsigned int space)
{
   if (space > (unsigned int)mio_nfds(mixer->hdl))
      return -1;

   return mio_pollfd(mixer->hdl, pfds, POLLOUT | POLLIN);
}

int
snd_mixer_poll_descriptors_revents(snd_mixer_t *mixer, struct pollfd *pfds, unsigned int nfds, unsigned short *revents)
{
   if (!revents || nfds > (unsigned int)mio_nfds(mixer->hdl))
      return -1;

   *revents = mio_revents(mixer->hdl, pfds);
   return 0;
}

int
snd_mixer_handle_events(snd_mixer_t *mixer)
{
   get_controls(mixer);
   return 0;
}

struct _snd_mixer_selem_id {
   const char *name;
};

int
snd_mixer_selem_id_malloc(snd_mixer_selem_id_t **ptr)
{
   return ((*ptr = calloc(1, sizeof(**ptr))) ? 0 : -1);
}

void
snd_mixer_selem_id_free(snd_mixer_selem_id_t *obj)
{
   free(obj);
}

void
snd_mixer_selem_id_set_name(snd_mixer_selem_id_t *obj, const char *val)
{
   obj->name = val;
}

snd_mixer_elem_t*
snd_mixer_find_selem(snd_mixer_t *mixer, const snd_mixer_selem_id_t *id)
{
   for (snd_mixer_elem_t *elem = mixer->controls; elem; elem = elem->next) {
      if (elem->name && id->name && !strcasecmp(elem->name, id->name))
         return elem;
   }

   return NULL;
}

snd_mixer_elem_t*
snd_mixer_first_elem(snd_mixer_t *mixer)
{
   return mixer->controls;
}

snd_mixer_elem_t*
snd_mixer_elem_next(snd_mixer_elem_t *elem)
{
   return elem->next;
}

void
snd_mixer_selem_get_id(snd_mixer_elem_t *element, snd_mixer_selem_id_t *id)
{
   id->name = element->name;
}

const char*
snd_mixer_selem_get_name(snd_mixer_elem_t *elem)
{
   return elem->name;
}

int
snd_mixer_selem_get_playback_volume(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long *value)
{
   if (value) *value = ((float)elem->vol / (float)0x7f) * 100;
   return 0;
}

int
snd_mixer_selem_get_playback_volume_range(snd_mixer_elem_t *elem, long *min, long *max)
{
   if (min) *min = 0;
   if (max) *max = 0x7f;
   return 0;
}

int
snd_mixer_selem_get_playback_dB(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long *value)
{
   if (value) *value = (long)elem->vol - 0x7f;
   return 0;
}

int
snd_mixer_selem_set_playback_dB(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long value, int dir)
{
   setvol(elem->mixer, elem->index, (elem->vol = value + 0x7f));
   return 0;
}

int
snd_mixer_selem_get_playback_dB_range(snd_mixer_elem_t *elem, long *min, long *max)
{
   if (max) *max = 0;
   if (min) *min = -127;
   return 0;
}

int
snd_mixer_selem_get_playback_switch(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, int *value)
{
   *value = (elem->vol > 0);
   return 0;
}

int
snd_mixer_selem_set_playback_switch(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, int value)
{
   if (value) {
      elem->muted_vol = (elem->muted_vol ? elem->muted_vol : 10);
      setvol(elem->mixer, elem->index, (elem->vol = elem->muted_vol));
   } else {
      elem->muted_vol = elem->vol;
      setvol(elem->mixer, elem->index, (elem->vol = 0));
   }
   return 0;
}

int
snd_mixer_selem_has_playback_volume(snd_mixer_elem_t *elem)
{
   return true;
}

int
snd_mixer_selem_has_playback_volume_joined(snd_mixer_elem_t *elem)
{
   return true;
}

int
snd_mixer_selem_has_playback_switch(snd_mixer_elem_t *elem)
{
   return true;
}

int
snd_mixer_selem_has_playback_switch_joined(snd_mixer_elem_t *elem)
{
   return true;
}

int
snd_mixer_selem_is_active(snd_mixer_elem_t *elem)
{
   return true;
}
