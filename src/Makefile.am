AUTOMAKE_OPTIONS = foreign

EXTRA_DIST = Win32MemoryLeakWarning.cpp \
	     StarterMemoryLeakWarning.cpp \
	     SymbianMemoryLeakWarning.cpp
INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/include/CppUnitLite

lib_LIBRARIES = libCppUnitLite.a
libCppUnitLite_a_SOURCES = Test.cpp \
		   	   TestRegistry.cpp \
		   	   TestResult.cpp \
		   	   SimpleString.cpp \
		   	   Failure.cpp \
			   EqualsFailure.cpp \
			   GccMemoryLeakWarning.cpp \
			   CommandLineTestRunner.cpp \
			   TestDefaultConfig.cpp
CppUnitLiteincludedir = $(includedir)/CppUnitLite
CppUnitLiteinclude_HEADERS = $(top_srcdir)/include/CppUnitLite/CommandLineTestRunner.h \
			     $(top_srcdir)/include/CppUnitLite/EqualsFailure.h \
			     $(top_srcdir)/include/CppUnitLite/Failure.h \
			     $(top_srcdir)/include/CppUnitLite/MemoryLeakWarning.h \
			     $(top_srcdir)/include/CppUnitLite/SimpleString.h \
			     $(top_srcdir)/include/CppUnitLite/Test.h \
			     $(top_srcdir)/include/CppUnitLite/TestHarness.h \
			     $(top_srcdir)/include/CppUnitLite/TestRegistry.h \
			     $(top_srcdir)/include/CppUnitLite/TestResult.h \
			     $(top_srcdir)/include/CppUnitLite/TestDefaultConfig.h

