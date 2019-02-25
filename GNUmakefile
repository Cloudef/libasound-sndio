PREFIX ?= /usr/local
libdir ?= /lib
includedir ?= /include
pkgconfigdir ?= /lib/pkgconfig

MAKEFLAGS += --no-builtin-rules

WARNINGS = -Wall -Wextra -Wpedantic -Wformat=2 -Wstrict-aliasing=3 -Wstrict-overflow=5 -Wstack-usage=64000 \
	-Wfloat-equal -Wcast-align -Wpointer-arith -Wchar-subscripts -Warray-bounds=2

override CFLAGS ?= -g -O2 $(WARNINGS)
override CFLAGS += -std=c11
override CPPFLAGS ?= -D_FORTIFY_SOURCE=2
override CPPFLAGS += -Iinclude
override LDFLAGS += -fPIC

libs = libasound.so.2.0.0
libsymlinks = libasound.so.2 libasound.so
pkgconfigs = alsa.pc
all: $(libs) $(libsymlinks) $(pkgconfigs)

%.pc: %.pc.in
	m4 -DINCLUDEDIR="$(PREFIX)$(includedir)" -DLIBDIR="$(PREFIX)$(libdir)" $^ > $@

libasound.so.2.0.0: private override CPPFLAGS += -D_DEFAULT_SOURCE
libasound.so.2.0.0: private override CPPFLAGS += -DBYTE_ORDER=__BYTE_ORDER -DLITTLE_ENDIAN=__LITTLE_ENDIAN -DBIG_ENDIAN=__BIG_ENDIAN
libasound.so.2.0.0: private override WARNINGS += -Wno-unused-parameter
libasound.so.2.0.0: private override CFLAGS += -Wno-deprecated-declarations
libasound.so.2.0.0: private override LDFLAGS += -Wl,--version-script=libasound.map -Wl,-soname,libasound.so.2
libasound.so.2.0.0: private override LDLIBS += -lsndio
libasound.so.2.0.0: src/libasound.c src/pcm.c src/mixer.c src/util/dsp.c src/util/dsp.h src/util/sysex.h src/util/defs.h src/util/util.h src/stubs.h src/symversioning-hell.h libasound.map
	$(LINK.c) -shared $(filter %.c,$^) $(LDLIBS) -o $@

libasound.so.2: libasound.so.2.0.0
	ln -fs $^ $@

libasound.so: libasound.so.2.0.0
	ln -fs $^ $@

install-lib: $(libs)
	install -Dm755 $^ -t "$(DESTDIR)$(PREFIX)$(libdir)"

install-symlinks: $(libsymlinks)
	chmod 755 $^
	mkdir -p "$(DESTDIR)$(PREFIX)$(libdir)"
	cp -P $^ "$(DESTDIR)$(PREFIX)$(libdir)"

install-pkgconfig: $(pkgconfigs)
	install -Dm755 $^ -t "$(DESTDIR)$(PREFIX)$(pkgconfigdir)"

install-include:
	mkdir -p "$(DESTDIR)$(PREFIX)$(includedir)"
	cp -r include/alsa "$(DESTDIR)$(PREFIX)$(includedir)/"

install: install-lib install-symlinks install-pkgconfig install-include

clean:
	$(RM) $(libs) $(libsymlinks) $(pkgconfigs)

.PHONY: all clean install
