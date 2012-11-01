//
// Copyright (c) 2004 Michael Feathers and James Grenning
// Released under the terms of the GNU General Public License version 2 or later.
//


///////////////////////////////////////////////////////////////////////////////
//
// EqualsFailure.H
//
// EqualsFailure is a class which holds information pertaining to a specific
// test failure.
//
///////////////////////////////////////////////////////////////////////////////


#ifndef EQUALS_FAILURE_H
#define EQUALS_FAILURE_H

#include "SimpleString.h"
#include "Failure.h"


class EqualsFailure : public Failure
{

public:
    EqualsFailure(Test*,
                    const SimpleString& expected,
                    const SimpleString& actual);

protected:
    virtual void printSpecifics() const;

private:
    EqualsFailure& operator=(const EqualsFailure&);

};


#endif
