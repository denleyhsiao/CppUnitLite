#include "CppUnitLite/TestHarness.h"

int main(int argc, char* argv[])
{

	TestResult tr;
	TestRegistry::runAllTests(tr);
	return 0;
}