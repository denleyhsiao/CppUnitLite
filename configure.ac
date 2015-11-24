#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT(CppUnitLite, 3.0, xiao_dli@justtodo.com)
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/Test.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE

# Checks for library functions.

# add --enable-debug parameter
AC_ARG_ENABLE([debug],
    [AS_HELP_STRING([--enable-debug],[debug program(default is no)])],
    [CXXFLAGS="${CFLAGS} -DDEBUG -Wall -g -O2"],
    [CXXFLAGS="-O2"])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/DequeTest/Makefile
                 test/StackTest/Makefile
                 test/TemplateDequeTest/Makefile
                 test/TestHarness/Makefile])
AC_OUTPUT
