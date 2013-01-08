//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//


#include "Test.h"
#include "TestRegistry.h"
#include "TestResult.h"
#include "Failure.h"
#include "EqualsFailure.h"
#include <stdio.h>

namespace
{
	void doNothing() {}
}


Test::Test (const SimpleString& groupName, 
            const SimpleString& testName, 
            const SimpleString& fileName, 
            int lineNumber, 
            void (*setUp)(), 
            void (*tearDown)()) 
			: group_(groupName)
			, name_(testName) 
			, file_(fileName)
			, lineNumber_(lineNumber)
			, setUp_(setUp)
			, tearDown_(tearDown)
{
	TestRegistry::addTest (this);
}

IgnoredTest::IgnoredTest(
						 const SimpleString& groupName, 
						 const SimpleString& testName, 
						 const SimpleString& fileName, 
						 int lineNumber)
						 : Test(groupName, testName, fileName, lineNumber, doNothing, doNothing) 
{
}

void IgnoredTest::run(TestResult& result)
{
	result.countIgnored();
}


Test *Test::getNext() const
{
	return next_;
}


void Test::setNext(Test *test)
{	
	next_ = test;
}

const SimpleString& Test::getName() const
{	
	
	return name_;
}

SimpleString Test::getFormattedName() const
{	
    const char* format = "%s(%s, %s)";
    char *stage = new char [strlen(format) - (3 * strlen("%s"))
        + getMacroName().size()
		+ group_.size () 
		+ name_.size ()
		+ 1];
	
	sprintf(stage, format,
		getMacroName().asCharString(),
		      group_.asCharString(), 
			  name_.asCharString());
	
	SimpleString formattedName(stage);
	
    delete[] stage;
	return formattedName;
}

const SimpleString& Test::getFile() const
{	
	return file_;
}


int Test::getLineNumber() const
{
    return lineNumber_;
}

void Test::setUp()
{
	(*setUp_)();
}

void Test::tearDown()
{
	(*tearDown_)();
}

