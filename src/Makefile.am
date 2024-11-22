AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS)

vmod_LTLIBRARIES = libvmod_wsinfo.la

libvmod_wsinfo_la_SOURCES = \
	vmod_wsinfo.c

nodist_libvmod_wsinfo_la_SOURCES = \
	vcc_wsinfo_if.c \
	vcc_wsinfo_if.h

dist_man_MANS = vmod_wsinfo.3

@BUILD_VMOD_WSINFO@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_wsinfo="$(VMOD_WSINFO)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_wsinfo.vcc \
	$(VMOD_TESTS)
