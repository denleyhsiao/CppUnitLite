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
    failure.Print();		
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
		fprintf (stdout, "\nErrors (%ld failures, ", failureCount);
	else
		fprintf (stdout, "\nOK (");
	fprintf (stdout, "%ld tests , %ld ran, %ld checks, %ld ignored, %ld filtered out)\n", 
		testCount, runCount, checkCount, ignoredCount , filteredOutCount);
}
