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

Failure::Failure( const Failure& other)
{
	this->testName = other.testName;
	this->fileName = other.fileName;
	this->lineNumber = other.lineNumber;
	this->message = other.message;
}

void Failure::setMessage( const char* value )
{
	message = value;
}

const char* Failure::getMessage() const
{
	return message.asCharString();	
}

void Failure::printLeader()const
{
    fprintf (stdout, "\nFailure in %s\n\t%s\n\tline: %ld\n",
        testName.asCharString(),
        fileName.asCharString(),
        lineNumber);
}

void Failure::print()const
{
    printLeader();
    printSpecifics();
    printTrailer();
}

void Failure::printSpecifics()const
{
    fprintf (stdout, "\t%s",
		message.asCharString());
}

void Failure::printTrailer()const
{
    fprintf (stdout, "\n\n");
}
