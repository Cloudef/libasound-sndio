PREFIX ?= /usr/local
libdir ?= /lib
includedir ?= /include
pkgconfigdir ?= /lib/pkgconfig

MAKEFLAGS += --no-builtin-rules

WARNINGS := -Wall -Wextra -Wpedantic -Wformat=2 -Wstrict-aliasing=3 -Wstrict-overflow=5 -Wstack-usage=12500 \
	-Wfloat-equal -Wcast-align -Wpointer-arith -Wchar-subscripts -Warray-bounds=2

override CFLAGS ?= -g
override CFLAGS += -std=c11 $(WARNINGS)
override CPPFLAGS += -Iinclude

libs = libasound.so
libsymlinks = libasound.so.2 libasound.so.2.0.0
pkgconfigs = alsa.pc
all: $(libs)

%.so:
	$(LINK.c) $(filter %.c,$^) $(LDLIBS) -fPIC -shared -Wl,-soname,$@.$(soabi).$(sompatch) -o $@.$(soabi).$(sompatch)
	ln -fs $@.$(soabi).$(sompatch) $@.$(soabi)
	ln -fs $@.$(soabi).$(sompatch) $@

%.pc: %.pc.in
	m4 -DINCLUDEDIR="$(PREFIX)$(includedir)" -DLIBDIR="$(PREFIX)$(libdir)" $^ > $@

libasound.so: private override soabi=2
libasound.so: private override sompatch=0.0
libasound.so: private override CPPFLAGS += -D_POSIX_SOURCE
libasound.so: private override CFLAGS += -Wno-unused-parameter -Wno-deprecated-declarations
libasound.so: private override LDFLAGS += -Wl,--version-script=libasound.map
libasound.so: private override LDLIBS += -lsndio
libasound.so: libasound.c libasound.map stubs.h symversioning-hell.h alsa.pc

install-lib: $(libs) $(libsymlinks)
	install -Dm755 $^ -t "$(DESTDIR)$(PREFIX)$(libdir)"

install-pkgconfig: $(pkgconfigs)
	install -Dm755 $^ -t "$(DESTDIR)$(PREFIX)$(pkgconfigdir)"

install-include:
	install -Dm755 -d include/alsa "$(DESTDIR)$(PREFIX)$(includedir)"

install: install-lib install-pkgconfig install-include

clean:
	$(RM) $(libs) $(libsymlinks) $(pkgconfigs)

.PHONY: all clean install
