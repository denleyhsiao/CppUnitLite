//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//


#include "CppUnitLite/SimpleString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static const int DEFAULT_SIZE = 20;

SimpleString::SimpleString ()
: buffer(new char [1])
{
	buffer [0] = '\0';
}


SimpleString::SimpleString (const char *otherBuffer)
: buffer (new char [strlen (otherBuffer) + 1])
{
	strcpy (buffer, otherBuffer);
}

SimpleString::SimpleString (const SimpleString& other)
{
	buffer = new char [other.size() + 1];
	strcpy(buffer, other.buffer);
}


SimpleString& SimpleString::operator= (const SimpleString& other)
{
	if (this != &other)
	{
		delete[] buffer;
		buffer = new char [other.size() + 1];
		strcpy(buffer, other.buffer);
	}
	return *this;
}

bool SimpleString::contains(const SimpleString& other) const
{
    return strstr(buffer, other.buffer) != NULL;
}

char *SimpleString::asCharString () const
{
	return buffer;
}

int SimpleString::size() const
{
	return strlen (buffer);
}

SimpleString::~SimpleString ()
{
	delete [] buffer;
}


bool operator== (const SimpleString& left, const SimpleString& right)
{
  return 0 == strcmp (left.asCharString (), right.asCharString ());
}


SimpleString StringFrom (bool value)
{
	char buffer [sizeof ("false") + 1];
	sprintf (buffer, "%s", value ? "true" : "false");
	return SimpleString(buffer);
}

SimpleString StringFrom (const char *value)
{
	return SimpleString(value);
}

SimpleString StringFrom (long value)
{
	char buffer [DEFAULT_SIZE];
	sprintf (buffer, "%ld", value);

	return SimpleString(buffer);
}

SimpleString StringFrom (double value)
{
	char buffer [DEFAULT_SIZE];
	sprintf (buffer, "%lf", value);

	return SimpleString(buffer);
}

SimpleString StringFrom (const SimpleString& value)
{
	return SimpleString(value);
}
