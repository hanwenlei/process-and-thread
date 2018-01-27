#include<cstdlib>
#include<process.h>
#include"CL_Thread.h"

CL_Thread::CL_Thread(CL_ManagerFunction* pManagerFunction, bool pAutoDelete):CL_Manager(pManagerFunction), m_AutoDelete(pAutoDelete)
{
	m_run = false;
	m_pvParam = NULL;
	m_WaitForNewThread.CreateEv();
	m_WaitForOldThread.CreateEv();
}

CL_Thread::~CL_Thread()
{
	CloseHandle(m_thread);
}

unsigned int CL_Thread::RunThreadFunc(void* pParam)
{
	CL_Thread* pThread = (CL_Thread*)pParam;
	void* pContent = pThread->m_pvParam;
	pThread->m_pvParam = NULL;
	pThread->m_WaitForNewThread.SetEv();
	pThread->m_WaitForOldThread.WaitEv();
	pThread->m_pManagerFunction->RunFunction(pContent);
	
	if(pThread->m_AutoDelete)
	{
		delete pThread;
	}
	return 0;
}

int CL_Thread::Run(void* pParam)
{
	if(m_run)
	{
		#if _DEBUG
		MessageBox(NULL, "One object can only run a thread!", "Error!", MB_OK);
		#endif
		return -1;
	}
	
	m_pvParam = pParam;
	m_thread = (HANDLE)_beginthreadex(NULL, 0, (unsigned (_stdcall*)(void*))RunThreadFunc, this, 0, &m_ThreadId);
	
	if(m_thread == 0)
	{
		#if _DEBUG
		MessageBox(NULL, "Creating a thread fails!", "Error!", MB_OK);
		#endif
		delete this;
		return -1;
	}
	else
	{
		m_run = true;
	}
	
	m_WaitForNewThread.WaitEv();
	m_WaitForOldThread.SetEv();
	
	if(m_AutoDelete)
	{
		PrepareToTerminate();
	}
	return 0;
}

int CL_Thread::PrepareToTerminate()
{
	if(m_AutoDelete)
	{
		return -1;
	}
	
	if(!m_run)
	{
		return -1;
	}
	
	SuspendThread(m_thread);
	delete this;
	return 0;
}

HANDLE CL_Thread::GetHandle()
{
	return m_thread;
}

DWORD CL_Thread::GetID()
{
	return m_ThreadId;
}

int CL_Thread::GetThreadPrio()
{
	return GetThreadPriority(m_thread);
}

int CL_Thread::SetThreadPrio(int pPriority)
{
	return SetThreadPriority(m_thread, pPriority);
}

void* CL_Thread::GetParam()
{
	return m_pvParam;
}

int CL_Thread::SetParam(void* pParam)
{
	m_pvParam = pParam;
	return 0;
}