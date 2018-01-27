#ifndef _CL_COMMUNICATIONMANAGER_H_
#define _CL_COMMUNICATIONMANAGER_H_

#include<windows.h>

class CL_CommunicationManager
{
private:
	CL_CommunicationManager(const CL_CommunicationManager&);
	CL_CommunicationManager& operator= (const CL_CommunicationManager&);
	
public:
	CL_CommunicationManager();
	virtual ~CL_CommunicationManager();
	virtual int PostManagerMessage(CL_Manager* pManager = NULL, MSG* pmsg = NULL) = 0;
};

#endif