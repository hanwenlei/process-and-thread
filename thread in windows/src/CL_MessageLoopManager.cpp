#include"CL_MessageLoopManager.h"

CL_MessageLoopManager::CL_MessageLoopManager(CL_MessageObserver* pMessageObserver)
{
	if(pMessageObserver == NULL)
	{
		#if _DEBUG
		MessageBox(NULL, "pMessageObserver cannot be null!", "Error!", MB_OK);
		#endif
	}
	m_pMessageObserver = pMessageObserver;
}

CL_MessageLoopManager::~CL_MessageLoopManager()
{
	delete m_pMessageObserver;
}

unsigned CL_MessageLoopManager::EnterMessageLoop()
{
	m_pMessageObserver->InitObserver(this);
	while(true)
	{
		MSG* temp = WaitAndGetMessage();
		if(temp == NULL)
		{
			continue;
		}
		
		Dispatch(temp);
		delete temp;
		
		if(temp->message == WM_QUIT)
		{
			break;
		}
	}
	return 0;
}

int CL_MessageLoopManager::RegisterFunc(MSG* pmsg, ManageMessage pMessageFunction)
{
	if(pMessageFunction == NULL)
	{
		return -1;
	}
	m_MessageMap[pmsg->message] = pMessageFunction;
	return 0;
}

int CL_MessageLoopManager::Dispatch(MSG* pmsg)
{
	map<UINT, ManageMessage>::iterator it;
	it = m_MessageMap.find(pmsg->message);
	if(it == m_MessageMap.end())
	{
		return -1;
	}
	(m_pMessageObserver->*(it->second))(pmsg);
	return 0;
}