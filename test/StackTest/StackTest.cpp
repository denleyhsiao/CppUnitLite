#include "CppUnitLite/TestHarness.h"
#include "Stack.h"
#include <string>

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
  std::string b = "asa";
  CHECK_EQUAL(std::string("asa"), b);
}