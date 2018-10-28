PREFIX ?= /usr/local
libdir ?= /lib
includedir ?= /include

MAKEFLAGS += --no-builtin-rules

WARNINGS := -Wall -Wextra -Wpedantic -Wformat=2 -Wstrict-aliasing=3 -Wstrict-overflow=5 -Wstack-usage=12500 \
	-Wfloat-equal -Wcast-align -Wpointer-arith -Wchar-subscripts -Warray-bounds=2

override CFLAGS ?= -g
override CFLAGS += -std=c11 $(WARNINGS)
override CPPFLAGS += -Iinclude

libs = libasound.so
all: $(libs)

%.so:
	$(LINK.c) $(filter %.c,$^) $(LDLIBS) -fPIC -shared -o $@

libasound.so: private override CPPFLAGS += -D_POSIX_SOURCE
libasound.so: private override CFLAGS += -Wno-unused-parameter -Wno-deprecated-declarations
libasound.so: private override LDFLAGS += -Wl,--version-script=libasound.map
libasound.so: private override LDLIBS += -lsndio
libasound.so: libasound.c libasound.map stubs.h symversioning-hell.h

install-lib: $(libs)
	install -Dm755 $^ -t "$(DESTDIR)$(PREFIX)$(libdir)"

install-include:
	install -Dm755 -d include/alsa "$(DESTDIR)$(PREFIX)$(includedir)"

install: install-lib install-include

clean:
	$(RM) $(libs)

.PHONY: all clean install
