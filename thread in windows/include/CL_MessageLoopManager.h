#ifndef _CL_MESSAGELOOPMANAGER_H_
#define _CL_MESSAGELOOPMANAGER_H_

#include<windows.h>
#include<map>
#include"CL_MessageObserver.h"

using namespace std;

typedef int (CL_MessageObserver::*ManageMessage)(MSG*);

class CL_MessageLoopManager
{
private:
	CL_MessageLoopManager(const CL_MessageLoopManager&);
	CL_MessageLoopManager& operator= (const CL_MessageLoopManager&);

protected:
	CL_MessageObserver* m_pMessageObserver;
	map<UINT, ManageMessage> m_MessageMap;
	virtual MSG* WaitAndGetMessage() = 0;
	virtual int Dispatch(MSG* pmsg = NULL);

public:
	CL_MessageLoopManager(CL_MessageObserver* pMessageObserver);
	virtual ~CL_MessageLoopManager();
	virtual unsigned EnterMessageLoop();
	virtual int RegisterFunc(MSG* pmsg, ManageMessage pMessageFunction = NULL);
};

#endif