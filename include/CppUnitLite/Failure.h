//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//


///////////////////////////////////////////////////////////////////////////////
//
// FAILURE.H
//
// Failure is a class which holds information pertaining to a specific
// test failure. It can be overriden for more complex failure messages
//
///////////////////////////////////////////////////////////////////////////////


#ifndef FAILURE_H
#define FAILURE_H

#include "SimpleString.h"

class Test;

class Failure
{

public:
    Failure(Test*, const SimpleString& theMessage);
    Failure(Test*);
    Failure(const Failure& other);
	virtual ~Failure() {}

    virtual void print() const;

protected:
	void setMessage(const char* value);
	const char* getMessage() const;
    
private:
	Failure& operator=(const Failure&);
	virtual void printLeader() const;
    virtual void printSpecifics() const;
    virtual void printTrailer() const;
	
	SimpleString message;
	SimpleString testName;
	SimpleString fileName;
	long lineNumber;
};


#endif
