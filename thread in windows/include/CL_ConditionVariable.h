#ifndef _CL_CONDITIONVARIABLE_H_
#define _CL_CONDITIONVARIABLE_H_

#include<windows.h>

class CL_ConditionVariable
{
private:
	PSRWLOCK m_pSrwlock;
	PCRITICAL_SECTION m_pCS;
	PCONDITION_VARIABLE m_pCV;
	bool m_IsWrite;
	CL_ConditionVariable(const CL_ConditionVariable&);
	CL_ConditionVariable& operator= (const CL_ConditionVariable&);

public:
	CL_ConditionVariable(bool pIsWrite);
	virtual ~CL_ConditionVariable();
	bool SleepCVCS(DWORD dwMilliseconds);
	bool SleepCVSRW(DWORD dwMilliseconds);
	int WakeCV();
	int WakeAllCV();
};

#endif