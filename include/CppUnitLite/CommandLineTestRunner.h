#ifndef D_CommadnLineTestRunner_H
#define D_CommadnLineTestRunner_H

#include "TestHarness.h"

class CommandLineTestRunner
{
public:
  static void RunAllTests(int ac, char** av);

private:
  static void SetOptions(int ac, char** av);
  static void SetRepeatCount(int ac, char** av, int& index);
  static int repeat;
};

#endif