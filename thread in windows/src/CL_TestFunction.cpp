#include"CL_TestFunction.h"

unsigned CL_TestFunction1::RunFunction(void* pParam)
{
	long i = (long)pParam;
	cout << "test thread : " << i << endl;
	return 0;
}

unsigned CL_TestFunction2::RunFunction(void* pParam)
{
	ST_Mutex* temp = (ST_Mutex*)pParam;
	temp->mutex.CreateMu(false);
	cout << "test mutex : " << temp->flag << endl;
	temp->flag++;
	cout << "test mutex : " << temp->flag << endl;
	temp->mutex.ReleaseMu();
	return 0;
}

unsigned CL_TestFunction3::RunFunction(void* pParam)
{
	try
	{
	    ST_Mutex* temp = (ST_Mutex*)pParam;
	    CL_CriticalSection cs;
	    temp->flag++;
	    test();
	}
	catch(...)
	{
	    cout << "test critical section exception" << endl;
	}
	return 0;
}

unsigned CL_TestFunction4::RunFunction(void* pParam)
{
	CL_Event* temp = (CL_Event*)pParam;
	//Sleep(2);
	temp->SetEv();
	return 0;
}

MSG* CL_TestCommunication::WaitAndGetMessage()
{
	MSG* temp = new MSG;
	GetMessage(temp, NULL, 0, 0);
	return temp;
}

int CL_TestObserver::InitObserver(CL_MessageLoopManager* pMessageLoopManager)
{
	MSG* pmsg = new MSG;
	pmsg->message = MESSAGE;
	pMessageLoopManager->RegisterFunc(pmsg, (ManageMessage)(&CL_TestCommunication::TestFunction));
	pmsg->message = WM_QUIT;
	pMessageLoopManager->RegisterFunc(pmsg, (ManageMessage)(&CL_TestCommunication::TestQuit));
	delete pmsg;
	return 0;
}