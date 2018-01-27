#include<cstdlib>
#include"CL_Mutex.h"

CL_Mutex::CL_Mutex():m_exit(false){}

CL_Mutex::~CL_Mutex()
{
	CloseHandle(m_mutex);
}

HANDLE CL_Mutex::CreateMu(BOOL bInitialOwner, PSECURITY_ATTRIBUTES psa, LPCTSTR pszName)
{
	if(m_exit)
	{
		#if _DEBUG
		MessageBox(NULL, "one object only has a mutex!", "Error!", MB_OK);
		#endif
		return 0;
	}
	m_mutex = CreateMutex(psa, bInitialOwner, pszName);
	if(m_mutex == 0)
	{
		#if _DEBUG
		MessageBox(NULL, "Creating a mutex fails!", "Error!", MB_OK);
		#endif
		return 0;
	}
	m_exit = true;
	return m_mutex;
}

HANDLE CL_Mutex::CreateMu(PSECURITY_ATTRIBUTES psa, LPCTSTR pszName, DWORD dwFlags, DWORD dwDesiredAccess)
{
	if(m_exit)
	{
		#if _DEBUG
		MessageBox(NULL, "one object only has a mutex!", "Error!", MB_OK);
		#endif
		return 0;
	}
	m_mutex = (HANDLE)CreateMutexEx(psa, pszName, dwFlags, dwDesiredAccess);
	if(m_mutex == 0)
	{
		#if _DEBUG
		MessageBox(NULL, "Creating a mutex fails!", "Error!", MB_OK);
		#endif
		return 0;
	}
	m_exit = true;
	return m_mutex;
}

int CL_Mutex::ReleaseMu()
{
	m_exit = false;
	ReleaseMutex(m_mutex);
	return 0;
}