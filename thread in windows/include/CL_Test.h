#ifndef _CL_TEST_H_
#define _CL_TEST_H_

#include"CL_TestFunction.h"

class CL_Test
{
public:
	CL_Test();
	~CL_Test();
	int TestThread();
	int TestMutex();
	int TestCriticalSection();
	int TestEvent();
	int TestCommunication();
};

#endif