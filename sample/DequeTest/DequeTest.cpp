#include "CppUnitLite/TestHarness.h"
#include "CppUnitLite/TestDefaultConfig.h"
#include "Deque.h"
#include <iostream>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

int main(int argc, char* argv[])
{
#ifdef DEBUG
	std::cout<<"DEBUG Version ..."<<std::endl;
#else
	std::cout<<"RELEASE Version ..."<<std::endl;
#endif

	CommandLineTestRunner::RunAllTests(argc, argv);

	return 0;
}

TEST( Deque, construction)
{
	Deque d;
	CHECK ( 0 == d.size() );
}

TEST( Deque, push_back)
{
	Deque d;
	d.push_back(0);
	CHECK (	1 == d.size() );
}

TEST( Deque, pop_back)
{
	Deque d;
	d.push_back(0);
	d.push_back(1);
	CHECK ( 1 == d.pop_back() );
	CHECK ( 0 == d.pop_back() );
}

TEST( Deque, grow)
{
	Deque d;
	for (int i = 0; i < 10; i++)
		d.push_back(i);
	d.push_back(10);
	CHECK ( 11 == d.size() );
	CHECK ( 10 == d.pop_back() );
}

TEST (Deque, push_front)
{
	Deque d;
	d.push_front(0);
	CHECK ( 1 == d.size() );
}

TEST (Deque, doit)
{
	Deque d;
	d.push_front(0);
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	CHECK ( 4 == d.size() );
	CHECK ( 0 == d.pop_front() );
	CHECK ( 3 == d.pop_back() );
}

TEST (Deque, pop_front)
{
	Deque d;
	d.push_front(0);
	CHECK( 1 == d.size());
	CHECK( 0 == d.pop_front());
	CHECK( 0 == d.size());
}

TEST (Deque, copy_construction)
{
	Deque d;
	d.push_front(1);
	Deque d2 = d;
	d.pop_front();
	CHECK( 1 == d2.pop_front());
}

TEST (Deque, assignment_operator)
{
	Deque d;
	d.push_front(1);
	Deque d2;
	d2 = d;
	d.pop_front();
	CHECK( 1 == d2.pop_front());
}

TEST (Deque, dont_try_suicide)
{
	Deque d;
	d.push_front(1);
	d = d;
	CHECK( 1 == d.pop_front());
}
