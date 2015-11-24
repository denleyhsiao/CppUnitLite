AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)/include

bin_PROGRAMS = StackTest
StackTest_SOURCES = StackMain.cpp \
		    StackTest.cpp \
		    Stack.h
StackTest_LDADD = $(top_builddir)/src/libCppUnitLite.a
