#include"CL_Test.h"

CL_Test::CL_Test(){}

CL_Test::~CL_Test(){}

int CL_Test::TestThread()
{
	CL_ManagerFunction* temp = new CL_TestFunction1;
	CL_Thread* pThread = new CL_Thread(temp, true);
	pThread->Run((void*)2);
	delete temp;
	return 0;
}

int CL_Test::TestMutex()
{
	CL_ManagerFunction* temp = new CL_TestFunction2;
    CL_Thread* pThread = new CL_Thread(temp, true);
    ST_Mutex* p = new ST_Mutex;
    p->flag = 2;
    
    pThread->Run(p);
    p->mutex.CreateMu(false);
    cout << "in TestMutex : " << p->flag << endl;
    p->flag++;
    cout << "in TestMutex : " << p->flag << endl;
    p->mutex.ReleaseMu();

	delete temp;
    delete p;
	return 0;
}

int CL_Test::TestCriticalSection()
{
	CL_ManagerFunction* temp = new CL_TestFunction3;
    CL_Thread* pThread = new CL_Thread(temp, true);
    ST_Mutex* p = new ST_Mutex;
    p->flag = 2;
    
    pThread->Run(p);
    Sleep(2);
    {
		CL_CriticalSection cs;
		p->flag++;
		cout << "in TestCriticalSection : " << p->flag << endl;
    }

	delete temp;
    delete p;
    return 0;
}

int CL_Test::TestEvent()
{
    CL_ManagerFunction* temp = new CL_TestFunction4;
    CL_Thread* pThread = new CL_Thread(temp, true);
    CL_Event* p = new CL_Event;
    pThread->Run(p);
    p->WaitEv();
    cout << "in TestEvent" << endl;

	delete temp;
    delete p;
    return 0;
}

int CL_Test::TestCommunication()
{
	CL_ManagerFunction* temp = new CL_FunctionForMessageLoop(new CL_TestCommunication(new CL_TestObserver));
	CL_Thread* pThread = new CL_Thread(temp, true);
	CL_ThreadCommunication* p = new CL_ThreadCommunication;
	MSG* pmsg = new MSG;
	
	pThread->Run(NULL);
	pmsg->message = MESSAGE;
	p->PostManagerMessage(pThread, pmsg);
	pmsg->message = WM_QUIT;
	p->PostManagerMessage(pThread, pmsg);

	delete temp;
    delete p;
    return 0;
}