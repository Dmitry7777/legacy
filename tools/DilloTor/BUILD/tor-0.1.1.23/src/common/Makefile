# Makefile.in generated automatically by automake 1.4-p6 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999, 2001 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = ../..

prefix = /data/Data/projekte/DilloTor/tor-0.1.1.23/binary
exec_prefix = /data/Data/projekte/DilloTor/tor-0.1.1.23/binary

bindir = /data/Data/projekte/DilloTor/tor-0.1.1.23/binary/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/tor
pkglibdir = $(libdir)/tor
pkgincludedir = $(includedir)/tor

top_builddir = ../..

ACLOCAL = aclocal-1.4
AUTOCONF = autoconf
AUTOMAKE = automake-1.4
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
host_alias = 
host_triplet = i686-pc-linux-gnu
BINDIR = /data/Data/projekte/DilloTor/tor-0.1.1.23/binary/bin
CC = gcc
CONFDIR = /data/Data/projekte/DilloTor/tor-0.1.1.23/binary/etc/tor
HAVE_LIB = @HAVE_LIB@
LIB = @LIB@
LOCALSTATEDIR = /data/Data/projekte/DilloTor/tor-0.1.1.23/binary/var
LOGFACILITY = 
LTLIB = @LTLIB@
MAKEINFO = /data/Data/projekte/DilloTor/tor-0.1.1.23/missing makeinfo
PACKAGE = tor
RANLIB = ranlib
TORGROUP = _tor
TORUSER = _tor
VERSION = 0.1.1.23

noinst_LIBRARIES = libor.a libor-crypto.a

#CFLAGS  = -Wall -Wpointer-arith -O2

libor_a_SOURCES = log.c util.c compat.c container.c
libor_crypto_a_SOURCES = crypto.c aes.c tortls.c torgzip.c

noinst_HEADERS = log.h crypto.h test.h util.h compat.h aes.h torint.h tortls.h strlcpy.c strlcat.c torgzip.h container.h ht.h
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = ../../orconfig.h
CONFIG_CLEAN_FILES = 
LIBRARIES =  $(noinst_LIBRARIES)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I../..
CPPFLAGS = 
LDFLAGS = 
LIBS = -lpthread -ldl  -levent -lssl -lcrypto
libor_a_LIBADD = 
libor_a_OBJECTS =  log.o util.o compat.o container.o
libor_crypto_a_LIBADD = 
libor_crypto_a_OBJECTS =  crypto.o aes.o tortls.o torgzip.o
AR = ar
CFLAGS = -g -O2 -Wall -g -O2
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
HEADERS =  $(noinst_HEADERS)

DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(libor_a_SOURCES) $(libor_crypto_a_SOURCES)
OBJECTS = $(libor_a_OBJECTS) $(libor_crypto_a_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .o .s
$(srcdir)/Makefile.in: Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps src/common/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-noinstLIBRARIES:

clean-noinstLIBRARIES:
	-test -z "$(noinst_LIBRARIES)" || rm -f $(noinst_LIBRARIES)

distclean-noinstLIBRARIES:

maintainer-clean-noinstLIBRARIES:

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

libor.a: $(libor_a_OBJECTS) $(libor_a_DEPENDENCIES)
	-rm -f libor.a
	$(AR) cru libor.a $(libor_a_OBJECTS) $(libor_a_LIBADD)
	$(RANLIB) libor.a

libor-crypto.a: $(libor_crypto_a_OBJECTS) $(libor_crypto_a_DEPENDENCIES)
	-rm -f libor-crypto.a
	$(AR) cru libor-crypto.a $(libor_crypto_a_OBJECTS) $(libor_crypto_a_LIBADD)
	$(RANLIB) libor-crypto.a

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags -o $$here/TAGS $(ETAGS_ARGS) $$tags  $$unique $(LISP))

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = src/common

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
aes.o: aes.c ../../orconfig.h aes.h ../common/torint.h util.h torint.h \
	compat.h log.h ../common/compat.h
compat.o: compat.c ../../orconfig.h compat.h torint.h log.h \
	../common/compat.h util.h strlcpy.c strlcat.c
container.o: container.c compat.h ../../orconfig.h torint.h util.h log.h \
	../common/compat.h container.h crypto.h ht.h
crypto.o: crypto.c ../../orconfig.h crypto.h log.h ../common/compat.h \
	../common/torint.h aes.h util.h torint.h compat.h container.h
log.o: log.c ../../orconfig.h util.h torint.h compat.h log.h \
	../common/compat.h
torgzip.o: torgzip.c ../../orconfig.h util.h torint.h compat.h log.h \
	../common/compat.h torgzip.h
tortls.o: tortls.c ../../orconfig.h crypto.h tortls.h ../common/crypto.h \
	../common/compat.h ../common/torint.h util.h torint.h compat.h \
	log.h
util.o: util.c ../../orconfig.h util.h torint.h compat.h log.h \
	../common/compat.h crypto.h container.h

info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am:
install-exec: install-exec-am

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am:
uninstall: uninstall-am
all-am: Makefile $(LIBRARIES) $(HEADERS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-noinstLIBRARIES mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-noinstLIBRARIES clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-noinstLIBRARIES distclean-compile \
		distclean-tags distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-noinstLIBRARIES \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-noinstLIBRARIES distclean-noinstLIBRARIES \
clean-noinstLIBRARIES maintainer-clean-noinstLIBRARIES \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
