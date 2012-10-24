#include "CppUnitLite/TestHarness.h"
#include "Stack.h"

namespace
{
	void SetUp()
	{
		
	}
	void TearDown()
	{
		
	}
}

TEST( Stack, creation )
{
  Stack s;
  LONGS_EQUAL(0, s.size());
  char* b = "asa";
  STRCMP_EQUAL("asa", b);
}