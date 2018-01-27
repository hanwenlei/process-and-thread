#include"CL_ThreadCommunication.h"

CL_ThreadCommunication::CL_ThreadCommunication(){}

CL_ThreadCommunication::~CL_ThreadCommunication(){}

int CL_ThreadCommunication::PostManagerMessage(CL_Manager* pManager, MSG* pmsg)
{
	if(pManager == NULL)
	{
		return false;
	}
	if(pmsg = NULL)
	{
		return false;
	}
	CL_Thread* temp = (CL_Thread*)pManager;
	DWORD id = temp->GetID();
	return PostThreadMessage(id, pmsg->message, pmsg->wParam, pmsg->lParam);
}