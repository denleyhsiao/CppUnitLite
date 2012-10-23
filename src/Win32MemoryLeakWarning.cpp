#include "MemoryLeakWarning.h"

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <windows.h>

#ifdef   _DEBUG
#define  SET_CRT_DEBUG_FIELD(a) \
_CrtSetDbgFlag((a) | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else
#define  SET_CRT_DEBUG_FIELD(a)   ((void) 0)
#endif


void MemoryLeakWarning::Enable()
{
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG|_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDERR );
	_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG|_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDERR );
	_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_DEBUG|_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
	SET_CRT_DEBUG_FIELD( _CRTDBG_LEAK_CHECK_DF );
}

void MemoryLeakWarning::Report()
{
	//windows reports leaks automatically when set up as above
}

_CrtMemState s1, s2, s3;


void MemoryLeakWarning::CheckPointUsage()
{
    _CrtMemCheckpoint( &s1 );
    //char* c = new char[64];
    //_CrtMemCheckpoint( &s2 );
    //_CrtMemDifference( &s3, &s1, &s2);
	
	
    //char* d = new char[1024];
    //_CrtMemCheckpoint( &s2 );
    //_CrtMemDifference( &s3, &s1, &s2);
	
    //delete c;
    //_CrtMemCheckpoint( &s2 );
    //_CrtMemDifference( &s3, &s1, &s2);
    //delete d;
    //_CrtMemCheckpoint( &s2 );
    //_CrtMemDifference( &s3, &s1, &s2);
	
}

bool MemoryLeakWarning::UsageIsNotBallanced()
{
    _CrtMemCheckpoint( &s2 );
    if (_CrtMemDifference( &s3, &s1, &s2) )
        return true;
    else
        return false;
}

const char* MemoryLeakWarning::Message()
{
    return "this test leaks";
}
