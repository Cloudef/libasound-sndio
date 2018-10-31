#pragma once

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <err.h>

#define WARN1(x) do { warn("asound: %s %s", __func__, x); } while (0)
#define WARN(x, ...) do { warn("asound: %s " x, __func__, ##__VA_ARGS__); } while (0)
#define WARNX1(x) do { warnx("asound: %s %s", __func__, x); } while (0)
#define WARNX(x, ...) do { warnx("asound: %s " x, __func__, ##__VA_ARGS__); } while (0)
#define ERRX1(x, y) do { errx(x, "asound: %s %s", __func__, y); } while (0)
#define ERRX(x, y, ...) do { errx(x, "asound: %s " y, __func__, ##__VA_ARGS__); } while (0)
#define ERR(x, y, ...) do { err(x, "asound: %s " y, __func__, ##__VA_ARGS__); } while (0)

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

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
