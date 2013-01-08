//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//



#include "EqualsFailure.h"

#include <cstdio>  // for sprintf()
#include <cstring> // for strlen()

EqualsFailure::EqualsFailure(Test* test,
                        const SimpleString& expected,
                        const SimpleString& actual)
: Failure(test)
{
	const char *format = "\texpected <%s>\n\tbut was  <%s>";

	char *stage = new char [strlen(format) - (2 * strlen("%s")) 
					+ expected.size () 
					+ actual.size ()
					+ 1];

	sprintf(stage, format, 
		expected.asCharString(), 
		actual.asCharString());

	setMessage(stage);
	delete[] stage;
}

void EqualsFailure::printSpecifics()const
{
    fprintf (stdout, "%s",
		getMessage());
}
