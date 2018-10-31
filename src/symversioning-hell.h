// symversioning... jesus fucking christ... stop doing this people...
// below is madness copied from upstream libasound's src/pcm/pcm.c

#define __SYMBOL_PREFIX ""
#define ASM_NAME(name) __SYMBOL_PREFIX name
#define INTERNAL(Name) Name

#define symbol_version(real, name, version) \
   __asm__(".symver " ASM_NAME(#real) "," ASM_NAME(#name) "@" #version)
#define default_symbol_version(real, name, version) \
   __asm__(".symver " ASM_NAME(#real) "," ASM_NAME(#name) "@@" #version)

#define OBSOLETE1(name, what, new) \
  default_symbol_version(__##name, name, new); \
  symbol_version(__old_##name, name, what);

#define __P_OLD_GET(pfx, name, val_type, ret_type) \
ret_type pfx##name(const snd_pcm_hw_params_t *params) \
{ \
   val_type val; \
   if (INTERNAL(name)(params, &val) < 0) \
      return 0; \
   return (ret_type)val; \
}

#define __P_OLD_GET1(pfx, name, val_type, ret_type) \
ret_type pfx##name(const snd_pcm_hw_params_t *params, int *dir) \
{ \
   val_type val; \
   if (INTERNAL(name)(params, &val, dir) < 0) \
      return 0; \
   return (ret_type)val; \
}

#define __OLD_GET(name, val_type, ret_type) __P_OLD_GET(__old_, name, val_type, ret_type)
#define __OLD_GET1(name, val_type, ret_type) __P_OLD_GET1(__old_, name, val_type, ret_type)

__OLD_GET(snd_pcm_hw_params_get_access, snd_pcm_access_t, int)
__OLD_GET(snd_pcm_hw_params_get_format, snd_pcm_format_t, int)
__OLD_GET(snd_pcm_hw_params_get_subformat, snd_pcm_subformat_t, int)
__OLD_GET(snd_pcm_hw_params_get_channels, unsigned int, int)
__OLD_GET1(snd_pcm_hw_params_get_rate, unsigned int, int)
__OLD_GET1(snd_pcm_hw_params_get_period_time, unsigned int, int)
__OLD_GET1(snd_pcm_hw_params_get_period_size, snd_pcm_uframes_t, snd_pcm_sframes_t)
__OLD_GET1(snd_pcm_hw_params_get_periods, unsigned int, int)
__OLD_GET1(snd_pcm_hw_params_get_buffer_time, unsigned int, int)
__OLD_GET(snd_pcm_hw_params_get_buffer_size, snd_pcm_uframes_t, snd_pcm_sframes_t)
__OLD_GET1(snd_pcm_hw_params_get_tick_time, unsigned int, int)

__OLD_GET(snd_pcm_hw_params_get_channels_min, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_rate_min, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_period_time_min, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_period_size_min, snd_pcm_uframes_t, snd_pcm_uframes_t)
__OLD_GET1(snd_pcm_hw_params_get_periods_min, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_buffer_time_min, unsigned int, unsigned int)
__OLD_GET(snd_pcm_hw_params_get_buffer_size_min, snd_pcm_uframes_t, snd_pcm_uframes_t)
__OLD_GET1(snd_pcm_hw_params_get_tick_time_min, unsigned int, unsigned int)

__OLD_GET(snd_pcm_hw_params_get_channels_max, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_rate_max, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_period_time_max, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_period_size_max, snd_pcm_uframes_t, snd_pcm_uframes_t)
__OLD_GET1(snd_pcm_hw_params_get_periods_max, unsigned int, unsigned int)
__OLD_GET1(snd_pcm_hw_params_get_buffer_time_max, unsigned int, unsigned int)
__OLD_GET(snd_pcm_hw_params_get_buffer_size_max, snd_pcm_uframes_t, snd_pcm_uframes_t)
__OLD_GET1(snd_pcm_hw_params_get_tick_time_max, unsigned int, unsigned int)

#define __P_OLD_NEAR(pfx, name, ret_type) \
ret_type pfx##name(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, ret_type val) \
{ \
   if (INTERNAL(name)(pcm, params, &val) < 0) \
      return 0; \
   return (ret_type)val; \
}

#define __P_OLD_NEAR1(pfx, name, ret_type) \
ret_type pfx##name(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, ret_type val, int *dir) \
{ \
   if (INTERNAL(name)(pcm, params, &val, dir) < 0) \
      return 0; \
   return (ret_type)val; \
}

#define __OLD_NEAR(name, ret_type) __P_OLD_NEAR(__old_, name, ret_type)
#define __OLD_NEAR1(name, ret_type) __P_OLD_NEAR1(__old_, name, ret_type)

__OLD_NEAR(snd_pcm_hw_params_set_channels_near, unsigned int)
__OLD_NEAR1(snd_pcm_hw_params_set_rate_near, unsigned int)
__OLD_NEAR1(snd_pcm_hw_params_set_period_time_near, unsigned int)
__OLD_NEAR1(snd_pcm_hw_params_set_period_size_near, snd_pcm_uframes_t)
__OLD_NEAR1(snd_pcm_hw_params_set_periods_near, unsigned int)
__OLD_NEAR1(snd_pcm_hw_params_set_buffer_time_near, unsigned int)
__OLD_NEAR(snd_pcm_hw_params_set_buffer_size_near, snd_pcm_uframes_t)
__OLD_NEAR1(snd_pcm_hw_params_set_tick_time_near, unsigned int)

#define __P_OLD_SET_FL(pfx, name, ret_type) \
ret_type pfx##name(snd_pcm_t *pcm, snd_pcm_hw_params_t *params) \
{ \
   ret_type val; \
   if (INTERNAL(name)(pcm, params, &val) < 0) \
      return 0; \
   return (ret_type)val; \
}

#define __P_OLD_SET_FL1(pfx, name, ret_type) \
ret_type pfx##name(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, int *dir) \
{ \
   ret_type val; \
   if (INTERNAL(name)(pcm, params, &val, dir) < 0) \
      return 0; \
   return (ret_type)val; \
}

#define __OLD_SET_FL(name, ret_type) __P_OLD_SET_FL(__old_, name, ret_type)
#define __OLD_SET_FL1(name, ret_type) __P_OLD_SET_FL1(__old_, name, ret_type)

__OLD_SET_FL(snd_pcm_hw_params_set_access_first, snd_pcm_access_t)
__OLD_SET_FL(snd_pcm_hw_params_set_format_first, snd_pcm_format_t)
__OLD_SET_FL(snd_pcm_hw_params_set_subformat_first, snd_pcm_subformat_t)
__OLD_SET_FL(snd_pcm_hw_params_set_channels_first, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_rate_first, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_period_time_first, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_period_size_first, snd_pcm_uframes_t)
__OLD_SET_FL1(snd_pcm_hw_params_set_periods_first, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_buffer_time_first, unsigned int)
__OLD_SET_FL(snd_pcm_hw_params_set_buffer_size_first, snd_pcm_uframes_t)
__OLD_SET_FL1(snd_pcm_hw_params_set_tick_time_first, unsigned int)

__OLD_SET_FL(snd_pcm_hw_params_set_access_last, snd_pcm_access_t)
__OLD_SET_FL(snd_pcm_hw_params_set_format_last, snd_pcm_format_t)
__OLD_SET_FL(snd_pcm_hw_params_set_subformat_last, snd_pcm_subformat_t)
__OLD_SET_FL(snd_pcm_hw_params_set_channels_last, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_rate_last, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_period_time_last, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_period_size_last, snd_pcm_uframes_t)
__OLD_SET_FL1(snd_pcm_hw_params_set_periods_last, unsigned int)
__OLD_SET_FL1(snd_pcm_hw_params_set_buffer_time_last, unsigned int)
__OLD_SET_FL(snd_pcm_hw_params_set_buffer_size_last, snd_pcm_uframes_t)
__OLD_SET_FL1(snd_pcm_hw_params_set_tick_time_last, unsigned int)

#define __P_OLD_GET_SW(pfx, name, ret_type) \
ret_type pfx##name(snd_pcm_sw_params_t *params) \
{ \
	ret_type val; \
	if (INTERNAL(name)(params, &val) < 0) \
		return 0; \
	return (ret_type)val; \
}

#define __OLD_GET_SW(name, ret_type) __P_OLD_GET_SW(__old_, name, ret_type)

__OLD_GET_SW(snd_pcm_sw_params_get_tstamp_mode, snd_pcm_tstamp_t)
__OLD_GET_SW(snd_pcm_sw_params_get_sleep_min, unsigned int)
__OLD_GET_SW(snd_pcm_sw_params_get_avail_min, snd_pcm_uframes_t)
__OLD_GET_SW(snd_pcm_sw_params_get_xfer_align, snd_pcm_uframes_t)
__OLD_GET_SW(snd_pcm_sw_params_get_start_threshold, snd_pcm_uframes_t)
__OLD_GET_SW(snd_pcm_sw_params_get_stop_threshold, snd_pcm_uframes_t)
__OLD_GET_SW(snd_pcm_sw_params_get_silence_threshold, snd_pcm_uframes_t)
__OLD_GET_SW(snd_pcm_sw_params_get_silence_size, snd_pcm_uframes_t)

OBSOLETE1(snd_pcm_hw_params_get_access, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_access_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_access_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_format, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_format_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_format_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_subformat, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_subformat_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_subformat_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_channels, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_channels_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_channels_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_channels_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_channels_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_channels_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_rate, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_rate_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_rate_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_rate_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_rate_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_rate_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_period_time, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_period_time_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_period_time_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_period_time_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_period_time_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_period_time_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_period_size, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_period_size_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_period_size_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_period_size_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_period_size_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_period_size_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_periods, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_periods_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_periods_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_periods_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_periods_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_periods_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_buffer_time, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_buffer_time_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_buffer_time_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_buffer_time_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_buffer_time_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_buffer_time_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_buffer_size, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_buffer_size_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_buffer_size_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_buffer_size_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_buffer_size_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_buffer_size_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_hw_params_get_tick_time, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_tick_time_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_get_tick_time_max, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_tick_time_near, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_tick_time_first, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_hw_params_set_tick_time_last, ALSA_0.9, ALSA_0.9.0rc4)

OBSOLETE1(snd_pcm_sw_params_get_tstamp_mode, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_sleep_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_avail_min, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_xfer_align, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_start_threshold, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_stop_threshold, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_silence_threshold, ALSA_0.9, ALSA_0.9.0rc4)
OBSOLETE1(snd_pcm_sw_params_get_silence_size, ALSA_0.9, ALSA_0.9.0rc4)
