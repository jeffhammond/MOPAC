# Configuration for mopac7.
# Copyright (c) 2003- Tommi Hassinen, Jean Brefort, Michael Banck.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.

# Process this file with autoconf to produce a configure script.

AC_INIT(mopac7,1.11)

AC_DEFINE([VERSION], ["1.11"], [This is the version of mopac7 to be built--it is set in the configure.ac])
AC_SUBST(VERSION, "1.11")

AC_PREREQ(2.48)
AC_CONFIG_SRCDIR(src/mopac7lib.c)

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)

AC_CANONICAL_HOST

top_builddir_=`pwd`
AC_SUBST(top_builddir_)

# Get any build/host and enable/disable flags now.
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

# Checks for programs.
# ^^^^^^^^^^^^^^^^^^^^

AC_PROG_CC
AC_PROG_INSTALL
#AC_PROG_RANLIB
AC_PATH_PROG(AR, ar, ar)
AC_PATH_PROG(SHELL, sh, /bin/sh)
AM_PROG_LIBTOOL
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)

# Checks for libraries.
# ^^^^^^^^^^^^^^^^^^^^^

AC_CHECK_LIB([m], [acos])

# Here is a check whether we have libf2c or libg2c (Jean Brefort).
# If libf2c is present, it is used and both the library and the executable is built.
# If only libg2c is present, then only the library is built and the executable is not built.
saved_flags=$CFLAGS
CFLAGS="-Dmain=MAIN__"
have_f2c="no"
AC_CHECK_LIB([f2c], [main], [have_f2c="yes"; CFLAGS=$saved_flags],
	[# If not found, try -lg2c:
	CFLAGS=$saved_flags;
	AC_CHECK_LIB([g2c], [main], ,
		# Still not found, drop out:
		AC_MSG_ERROR([Cannot find either f2c or g2c library])]
	)
)
AM_CONDITIONAL(HAVE_F2C,test "$have_f2c" = "yes")
# If we only have libg2c present, we must make a local copy of f2c.h
# header file that includes g2c.h file and contains some definitions.
if test "$have_f2c" = "no"; then
   echo "#include <g2c.h>" > src/f2c.h
   echo "#define VOID void" >> src/f2c.h
   AC_MSG_WARN(mopac7 program cannot be built without f2c)
   AC_MSG_WARN(a local copy of f2c.h header has been created in src/)
else
   rm -f src/f2c.h
fi

# Checks for header files.
# ^^^^^^^^^^^^^^^^^^^^^^^^

# Checks for typedefs, structures, and compiler characteristics.
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

AC_C_CONST
AC_C_INLINE

# Checks for library functions.
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

AC_OUTPUT(Makefile
	fortran/Makefile
	fortran/c_src_bak/Makefile
	src/Makefile
	tests/Makefile
	libmopac7.pc)
