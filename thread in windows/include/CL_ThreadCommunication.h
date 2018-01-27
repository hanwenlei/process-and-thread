#ifndef _CL_THREADCOMMUNICATION_H_
#define _CL_THREADCOMMUNICATION_H_

#include"CL_Thread.h"
#include"CL_CommunicationManager.h"

class CL_ThreadCommunication : public CL_CommunicationManager
{
private:
	CL_ThreadCommunication(const CL_ThreadCommunication&);
	CL_ThreadCommunication& operator= (const CL_ThreadCommunication&);
	
public:
	CL_ThreadCommunication();
	virtual ~CL_ThreadCommunication();
	virtual int PostManagerMessage(CL_Manager* pManager = NULL, MSG* pmsg = NULL);
};

#endif