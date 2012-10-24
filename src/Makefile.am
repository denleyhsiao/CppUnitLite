AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/include/CppUnitLite

lib_LIBRARIES = libCppUnitLite.a
libCppUnitLite_a_SOURCES = Test.cpp \
		   	   TestRegistry.cpp \
		   	   TestResult.cpp \
		   	   SimpleString.cpp \
		   	   Failure.cpp \
			   EqualsFailure.cpp \
			   GccMemoryLeakWarning.cpp \
			   CommandLineTestRunner.cpp
			 
EXTRA_DIST = Win32MemoryLeakWarning.cpp \
	     StarterMemoryLeakWarning.cpp \
	     SymbianMemoryLeakWarning.cpp
