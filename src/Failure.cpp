//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//



#include "Failure.h"
#include "Test.h"

#include <cstdio>  // for sprintf()
#include <cstring> // for strlen()


Failure::Failure(Test* test, const SimpleString& theMessage) 
: testName (test->getFormattedName()) 
, fileName (test->getFile()) 
, lineNumber (test->getLineNumber())
, message (theMessage)
{
}

Failure::Failure(Test* test) 
: testName (test->getFormattedName()) 
, fileName (test->getFile()) 
, lineNumber (test->getLineNumber())
, message("no message")
{
}


void Failure::PrintLeader()const
{
    fprintf (stdout, "\nFailure in %s\n\t%s\n\tline: %d\n",
        testName.asCharString(),
        fileName.asCharString(),
        lineNumber);
}

void Failure::Print()const
{
    PrintLeader();
    PrintSpecifics();
    PrintTrailer();
}

void Failure::PrintSpecifics()const
{
    fprintf (stdout, "\t%s",
		message.asCharString());
}

void Failure::PrintTrailer()const
{
    fprintf (stdout, "\n\n");
}


