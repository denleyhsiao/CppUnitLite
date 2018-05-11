#include "CppUnitLite/CppUnitLite.h"
#include "Deque.h"
#include <cassert>

namespace {
  Deque* d = NULL;
  void SetUp() {
    d = new Deque();
    assert(d != NULL);
  }
  
  void TearDown() {
    delete d;
    d = NULL;
  }
}

TEST( Deque, construction)
{
	CHECK ( 0 == d->size() );
}

TEST( Deque, push_back)
{
	d->push_back(0);
	CHECK (	1 == d->size() );
}

TEST( Deque, pop_back)
{
	d->push_back(0);
	d->push_back(1);
	CHECK ( 1 == d->pop_back() );
	CHECK ( 0 == d->pop_back() );
}

TEST( Deque, grow)
{
	for (int i = 0; i < 10; i++)
		d->push_back(i);
	d->push_back(10);
	CHECK ( 11 == d->size() );
	CHECK ( 10 == d->pop_back() );
}

TEST (Deque, push_front)
{
	d->push_front(0);
	CHECK ( 1 == d->size() );
}

TEST (Deque, doit)
{
	d->push_front(0);
	d->push_back(1);
	d->push_back(2);
	d->push_back(3);
	CHECK ( 4 == d->size() );
	CHECK ( 0 == d->pop_front() );
	CHECK ( 3 == d->pop_back() );
}

TEST (Deque, pop_front)
{
	d->push_front(0);
	CHECK( 1 == d->size());
	CHECK( 0 == d->pop_front());
	CHECK( 0 == d->size());
}

TEST (Deque, copy_construction)
{
	d->push_front(1);
	Deque d2 = *d;
	d->pop_front();
	CHECK( 1 == d2.pop_front());
}

TEST (Deque, assignment_operator)
{
	d->push_front(1);
	Deque d2;
	d2 = *d;
	d->pop_front();
	CHECK( 1 == d2.pop_front());
}

TEST (Deque, dont_try_suicide)
{
	d->push_front(1);
	*d = *d;
	CHECK( 1 == d->pop_front());
}
