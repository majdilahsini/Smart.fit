## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = admin

admin_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	verifier.c verifier.h \
        ajouter.c ajouter.h \
	afficher.c afficher.h \
	modifier.c modifier.h \
	reservation.c reservation.h \
	supprimer.c supprimer.h \
	affichercalen.c affichercalen.h
       

admin_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

