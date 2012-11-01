//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//


#include "TestResult.h"
#include "Failure.h"

#include <stdio.h>


TestResult::TestResult ()
: testCount(0)
, runCount(0)
, checkCount(0)
, failureCount (0)
, filteredOutCount(0)
, ignoredCount(0)
{
}


void TestResult::testsStarted () 
{
}


void TestResult::addFailure (const Failure& failure) 
{
    failure.print();		
	failureCount++;
}

void TestResult::countTest()
{
	testCount++;
}

void TestResult::countRun()
{
	runCount++;
}

void TestResult::countCheck()
{
	checkCount++;
}

void TestResult::countFilteredOut()
{
	filteredOutCount++;
}

void TestResult::countIgnored()
{
	ignoredCount++;
}

void TestResult::testsEnded () 
{
	if (failureCount > 0)
		fprintf (stdout, "\nErrors (%d failures, ", failureCount);
	else
		fprintf (stdout, "\nOK (");
	fprintf (stdout, "%d tests , %d ran, %d checks, %d ignored, %d filtered out)\n", 
		testCount, runCount, checkCount, ignoredCount , filteredOutCount);
}
