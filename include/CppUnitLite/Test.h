//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//

///////////////////////////////////////////////////////////////////////////////
//
// TEST.H
// 
// This file contains the Test class along with the macros which make effective
// in the harness.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TEST_H
#define TEST_H


#include "SimpleString.h"
#include <string.h>

class TestResult;



class Test
{
public:
	
	Test (const SimpleString& groupName, 
		const SimpleString& testName, 
		const SimpleString& fileName,
		int lineNumber,         
		void (*setUp)(), 
		void (*tearDown)());
	
	virtual void	run (TestResult& result) = 0;
	virtual SimpleString getFormattedName() const;
	
	void setNext(Test *test);
	Test *getNext () const;
	const SimpleString& getName() const;
	const SimpleString& getFile() const;
	int getLineNumber() const;
	void setUp();
	void tearDown();
	
protected:
	
	virtual SimpleString getMacroName() const {return "TEST";}
	
private:
	
	SimpleString group_;
	SimpleString name_;
	SimpleString file_;
	SimpleString formattedName_;
	int	lineNumber_;
	Test *next_;
	void (*setUp_)();
	void (*tearDown_)();
	
};

class IgnoredTest : public Test 
{
public:
	IgnoredTest(const SimpleString& groupName, 
		const SimpleString& testName, 
		const SimpleString& fileName,
		int lineNumber);      
	
	virtual void	run (TestResult& result);
	
protected:
	virtual SimpleString getMacroName() const {return "IGNORE_TEST";}
	
};



#define TEST(testGroup, testName)\
	class testGroup##testName##Test : public Test \
{ public: testGroup##testName##Test () : Test (#testGroup, #testName, __FILE__,__LINE__, &SetUp, &TearDown) {} \
	void run (TestResult& result_); } \
    testGroup##testName##Instance; \
void testGroup##testName##Test::run (TestResult& result_) 

#define IGNORE_TEST(testGroup, testName)\
	class testGroup##testName##Test : public IgnoredTest \
{ public: testGroup##testName##Test () : IgnoredTest (#testGroup, #testName, __FILE__,__LINE__) {} \
	void thisNeverRuns (TestResult& result_); } \
    testGroup##testName##Instance; \
void testGroup##testName##Test::thisNeverRuns (TestResult& result_) 

#define EXPORT_TEST_GROUP(testGroup)\
int externTestGroup##testGroup = 0;

#define IMPORT_TEST_GROUP(testGroup) \
	extern int externTestGroup##testGroup;\
int* p##testGroup = &externTestGroup##testGroup;

//Check any boolean condition
#define CHECK(condition)\
{ result_.countCheck(); \
	if (!(condition)) \
{ result_.addFailure (Failure (this, #condition)); return; } }


//This check needs the equality operator, and a StringFrom(YourType) function
#define CHECK_EQUAL(expected,actual)\
{ result_.countCheck(); \
	if ((expected) == (actual)) ;\
	else {result_.addFailure(EqualsFailure(this, StringFrom(expected), StringFrom(actual)));\
	return;}\
}

//This check checks for char* string equality using strcmp.  
//This makes up for the fact that CHECK_EQUAL only compares the pointers to char*'s
#define STRCMP_EQUAL(expected,actual)\
{ result_.countCheck(); \
	if (strcmp(expected, actual) != 0)\
{ result_.addFailure(EqualsFailure(this, StringFrom(expected), StringFrom(actual)));\
return;} }


//Check two long integers for equality
#define LONGS_EQUAL(expected,actual)\
{ result_.countCheck(); \
	long actualTemp = actual; \
	long expectedTemp = expected; \
	if ((expectedTemp) != (actualTemp)) \
{ result_.addFailure (EqualsFailure(this, StringFrom(expectedTemp), \
StringFrom(actualTemp))); return; } }


//Check two doubles for equality within a tolerance threshold
#define DOUBLES_EQUAL(expected,actual,threshold)\
{ result_.countCheck(); \
	double actualTemp = actual; \
	double expectedTemp = expected; \
	if (fabs ((expectedTemp)-(actualTemp)) > threshold) \
{ result_.addFailure (EqualsFailure(this, \
StringFrom((double)expectedTemp), StringFrom((double)actualTemp))); return; } }


//Fail if you get to this macro
#define FAIL(text) \
{ result_.addFailure (Failure (this,(text))); return; }

#endif
