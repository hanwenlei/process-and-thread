#ifndef _CL_MESSAGEOBSERVER_H_
#define _CL_MESSAGEOBSERVER_H_

class CL_MessageLoopManager;

class CL_MessageObserver
{
private:
	CL_MessageObserver(const CL_MessageObserver&);
	CL_MessageObserver& operator= (const CL_MessageObserver&);
	
public:
	CL_MessageObserver();
	virtual ~CL_MessageObserver();
	virtual int InitObserver(CL_MessageLoopManager* pMessageLoopManager) = 0;
};

#endif