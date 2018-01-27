#ifndef _CL_TESTFUNCTION_H_
#define _CL_TESTFUNCTION_H_
#define MESSAGE 100

#include<iostream>
#include"CL_Process.h"
#include"CL_CriticalSection.h"
#include"CL_ConditionVariable.h"
#include"CL_Mutex.h"
#include"CL_ThreadCommunication.h"
#include"CL_FunctionForMessageLoop.h"

struct ST_Mutex
{
	int flag;
	CL_Mutex mutex;
};

class CL_TestFunction1 : public CL_ManagerFunction
{
public:
	CL_TestFunction1(){}
	virtual ~CL_TestFunction1(){}
	virtual unsigned RunFunction(void* pParam);
};

class CL_TestFunction2 : public CL_ManagerFunction
{
public:
	CL_TestFunction2(){}
	virtual ~CL_TestFunction2(){}
	virtual unsigned RunFunction(void* pParam);
};

class CL_TestFunction3 : public CL_ManagerFunction
{
public:
	CL_TestFunction3(){}
	virtual ~CL_TestFunction3(){}
	virtual unsigned RunFunction(void* pParam);
	void test()
	{
		throw 3;
	}
};

class CL_TestFunction4 : public CL_ManagerFunction
{
public:
	CL_TestFunction4(){}
	virtual ~CL_TestFunction4(){}
	virtual unsigned RunFunction(void* pParam);
};

class CL_TestCommunication : public CL_MessageLoopManager
{
public:
	CL_TestCommunication(){}
	virtual ~CL_TestCommunication(){}
	virtual MSG* WaitAndGetMessage();
};

class CL_TestObserver : public CL_MessageObserver
{
public:
	CL_TestObserver(){}
	virtual ~CL_TestObserver(){}
	virtual int InitObserver(CL_MessageLoopManager* pMessageLoopManager);
	int TestFunction(MSG* pmsg)
	{
		cout << "Message is being dealed with : " << pmsg->message << endl;
		return 0;
	}
	int TestQuit(MSG* pmsg)
	{
		cout << "Quit!" << endl;
		return 0;
	}
};

#endif