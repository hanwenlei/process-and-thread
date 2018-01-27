#include"CL_Test.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CL_Test* temp = new CL_Test;
	temp->TestThread();
	delete temp;
	return 0;
}