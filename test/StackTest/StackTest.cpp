#include "CppUnitLite/TestHarness.h"
#include "CppUnitLite/TestDefaultConfig.h"
#include "Stack.h"

TEST( Stack, creation )
{
  Stack s;
  LONGS_EQUAL(0, s.size());
  char* b = "asa";
  STRCMP_EQUAL("asa", b);
}