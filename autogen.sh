#! /bin/sh

aclocal
autoheader
autoconf
automake --foreign --add-missing --copy
./configure --prefix=$(pwd)
make
make install

