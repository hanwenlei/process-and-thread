#include"CL_ConditionVariable.h"

CL_ConditionVariable::CL_ConditionVariable(bool pIsWrite):m_IsWrite(pIsWrite)
{
	m_pSrwlock = (PSRWLOCK)malloc(sizeof(SRWLOCK));
	m_pCS = (PCRITICAL_SECTION)malloc(sizeof(CRITICAL_SECTION));
	m_pCV = (PCONDITION_VARIABLE)malloc(sizeof(CONDITION_VARIABLE));
	InitializeCriticalSection(m_pCS);
	InitializeSRWLock(m_pSrwlock);
}

CL_ConditionVariable::~CL_ConditionVariable()
{
	DeleteCriticalSection(m_pCS);
	free(m_pSrwlock);
	free(m_pCS);
	free(m_pCV);
}

bool CL_ConditionVariable::SleepCVCS(DWORD dwMilliseconds)
{
	return SleepConditionVariableCS(m_pCV, m_pCS, dwMilliseconds);
}

bool CL_ConditionVariable::SleepCVSRW(DWORD dwMilliseconds)
{
	if(m_IsWrite)
	{
		return SleepConditionVariableSRW(m_pCV, m_pSrwlock, dwMilliseconds, 0);
	}
	else
	{
		return SleepConditionVariableSRW(m_pCV, m_pSrwlock, dwMilliseconds, CONDITION_VARIABLE_LOCKMODE_SHARED);
	}
}

int CL_ConditionVariable::WakeCV()
{
	WakeConditionVariable(m_pCV);
	return 0;
}

int CL_ConditionVariable::WakeAllCV()
{
	WakeAllConditionVariable(m_pCV);
	return 0;
}