#include"CL_FunctionForMessageLoop.h"

CL_FunctionForMessageLoop::CL_FunctionForMessageLoop(CL_MessageLoopManager* pMessageLoopManager)
{
	if(pMessageLoopManager == NULL)
	{
		#if _DEBUG
		MessageBox(NULL, "pMessageLoopManager cannot be null!", "Error!", MB_OK);
		#endif
	}
	m_pMessageLoopManager = pMessageLoopManager;
}

CL_FunctionForMessageLoop::~CL_FunctionForMessageLoop()
{
	delete m_pMessageLoopManager;
}

unsigned CL_FunctionForMessageLoop::RunFunction(void* pParam)
{
	return m_pMessageLoopManager->EnterMessageLoop();
}