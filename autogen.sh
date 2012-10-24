#! /bin/sh

aclocal
autoheader
autoconf
automake --foreign --add-missing --copy
./configure
make
# make install
# make distcheck
# make dist
# make distclean
