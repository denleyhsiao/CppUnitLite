AUTOMAKE_OPTIONS=foreign

SUBDIRS = src \
	  test/TestHarness \
	  test/DequeTest \
	  test/TemplateDequeTest \
	  test/StackTest

EXTRA_DIST = BUGS autogen.sh \
	     lib/.gitignore \
	     bin/.gitignore

dist-hook:
	cp -dpR $(top_srcdir)/build $(distdir)/build
