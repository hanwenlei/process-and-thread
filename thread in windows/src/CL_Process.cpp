#include<cstdlib>
#include"CL_Process.h"

CL_Process::CL_Process():CL_Manager(NULL), m_run(false)
{
	m_pProcInfo = (PPROCESS_INFORMATION)malloc(sizeof(PROCESS_INFORMATION));
	m_pStartInfo = (LPSTARTUPINFO)malloc(sizeof(STARTUPINFO));
	memset(m_pProcInfo, 0, sizeof(PROCESS_INFORMATION));
	memset(m_pStartInfo, 0, sizeof(STARTUPINFO));
	m_pStartInfo->cb = sizeof(STARTUPINFO);
}

CL_Process::~CL_Process()
{
	free(m_pStartInfo);
	free(m_pProcInfo);
}

int CL_Process::Run(void* pParam)
{
	if(m_run)
	{
		#if _DEBUG
		MessageBox(NULL, "One object can only run a process!", "Error!", MB_OK);
		#endif
		return -1;
	}
	
	int flag = CreateProcess(NULL, (char*)pParam, NULL, NULL, false, 0, NULL, NULL, m_pStartInfo, m_pProcInfo);
	
	if(flag)
	{
		m_process = m_pProcInfo->hProcess;
		m_run = true;
		CloseHandle(m_pProcInfo->hThread);
		CloseHandle(m_pProcInfo->hProcess);
	}
	else
	{
		m_run = false;
	}
	return flag;
}

HANDLE CL_Process::GetProcessHandle()
{
	return m_process;
}