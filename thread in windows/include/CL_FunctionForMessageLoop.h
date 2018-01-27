#ifndef _CL_FUNCTIONFORMESSAGELOOP_H_
#define _CL_FUNCTIONFORMESSAGELOOP_H_

#include"CL_ManagerFunction.h"
#include"CL_MessageLoopManager.h"

class CL_FunctionForMessageLoop : public CL_ManagerFunction
{
private:
	CL_MessageLoopManager* m_pMessageLoopManager;
	CL_FunctionForMessageLoop(const CL_FunctionForMessageLoop&);
	CL_FunctionForMessageLoop& operator= (const CL_FunctionForMessageLoop&);

public:
	CL_FunctionForMessageLoop(CL_MessageLoopManager* pMessageLoopManager);
	virtual ~CL_FunctionForMessageLoop();
	virtual unsigned RunFunction(void* pParam);
};

#endif