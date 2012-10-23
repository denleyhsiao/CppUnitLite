//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//

#ifndef D_EnableMemoryLeakWarning_h
#define D_EnableMemoryLeakWarning_h

class MemoryLeakWarning
{
public:
  static void Enable();
  static void Report();
  static void CheckPointUsage();
  static bool UsageIsNotBallanced();
  static const char* Message();
};

#endif
