#pragma once

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <err.h>

static inline int
do_debug(void)
{
   static int debug = -1;
   if (debug == -1) {
      const char *env = getenv("ASOUND_DEBUG");
      debug = (env && !!strcmp(env, "0"));
   }
   return debug;
}

#define WARN1(x) do { if (do_debug()) warn("asound: %s %s", __func__, x); } while(0)
#define WARN(x, ...) do { if (do_debug()) warn("asound: %s " x, __func__, ##__VA_ARGS__); } while (0)
#define WARNX1(x) do { if (do_debug()) warnx("asound: %s %s", __func__, x); } while (0)
#define WARNX(x, ...) do { if (do_debug()) warnx("asound: %s " x, __func__, ##__VA_ARGS__); } while (0)
#define ERRX1(x, y) do { errx(x, "asound: %s %s", __func__, y); } while (0)
#define ERRX(x, y, ...) do { errx(x, "asound: %s " y, __func__, ##__VA_ARGS__); } while (0)
#define ERR(x, y, ...) do { err(x, "asound: %s " y, __func__, ##__VA_ARGS__); } while (0)

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static inline char*
c_strdup(const char *str)
{
   size_t len = strlen(str);

   char *copy;
   if (!(copy = calloc(1, len + 1)))
      return NULL;

   memcpy(copy, str, len);
   return copy;
}
