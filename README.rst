.. image:: https://github.com/xcir/libvmod-wsinfo/actions/workflows/test.yml/badge.svg?branch=main
    :target: https://github.com/xcir/libvmod-wsinfo/actions/workflows/test.yml

============
vmod-wsinfo
============

------------------------------------
workspace info
------------------------------------

:Author: Shohei Tanaka(@xcir)
:Date: TBD
:Version: -
:Support Varnish Version: -
:Check Varnish Version: see .github/workflows/test.yml
:Manual section: 3

SYNOPSIS
========

import wsinfo;

Versioning(Source)
====================
[varnish-version].[library-version]

65.1 is v1 for Varnish6.5.x

Versioning(Package)
====================
[VRT-version].[Source-version]

120.65.1 is 65.1 for VRT12.0

============ ===============
VRT Version  Varnish Version 
------------ ---------------
16.0         7.2.x
15.0         7.1.x
14.0         7.0.x
13.0         6.6.x
12.0         6.5.x
11.0         6.4.x
10.0         6.3.x
9.0          6.2.x
8.0          6.1.x
7.1          6.0.4~6.0.x
7.0          6.0.0~6.0.3
============ ===============

DESCRIPTION
===========



Installation directories
------------------------

By default, the vmod ``configure`` script installs the built vmod in the
directory relevant to the prefix. The vmod installation directory can be
overridden by passing the ``vmoddir`` variable to ``make install``.


COMMON PROBLEMS
===============

* autogen.sh: error: possibly undefined macro: AC_MSG_ERROR

  Install ``autoconf-archive``

* configure: error: Need varnish.m4 -- see README.rst

  Check whether ``PKG_CONFIG_PATH`` and ``ACLOCAL_PATH`` were set correctly
  before calling ``autogen.sh`` and ``configure``

* Incompatibilities with different Varnish Cache versions

  Make sure you build this vmod against its correspondent Varnish Cache version.
  For instance, to build against Varnish Cache 4.1, this vmod must be built from
  branch 4.1.
