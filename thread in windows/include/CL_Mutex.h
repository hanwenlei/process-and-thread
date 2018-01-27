#ifndef _CL_MUTEX_H_
#define _CL_MUTEX_H_
#define CREATE_MUTEX_INITIAL_OWNER 0x00000001

#include<windows.h>

class CL_Mutex
{
private:
	HANDLE m_mutex;
	bool m_exit;
	CL_Mutex(const CL_Mutex&);
	CL_Mutex& operator= (const CL_Mutex&);
	
public:
	CL_Mutex();
	virtual ~CL_Mutex();
	HANDLE CreateMu(BOOL bInitialOwner, PSECURITY_ATTRIBUTES psa = NULL, LPCTSTR pszName = NULL);
	HANDLE CreateMu(PSECURITY_ATTRIBUTES psa = NULL, LPCTSTR pszName = NULL, DWORD dwFlags = CREATE_MUTEX_INITIAL_OWNER, DWORD dwDesiredAccess = 0);
	int ReleaseMu();
};

#endif