#ifndef _CL_PROCESS_H_
#define _CL_PROCESS_H_

#include<windows.h>
#include"CL_Manager.h"

class CL_Process : public CL_Manager
{
private:
	bool m_run;
	HANDLE m_process;
	LPSTARTUPINFO m_pStartInfo;
	PPROCESS_INFORMATION m_pProcInfo;
	void* m_pvParam;
	
public:
	CL_Process();
	virtual ~CL_Process();
	virtual int Run(void* pParam);
	HANDLE GetProcessHandle();
};

#endif