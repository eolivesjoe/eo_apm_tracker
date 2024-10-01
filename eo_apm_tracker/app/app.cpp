#include "app.h"

App::App()
{
}
App::~App()
{
}

std::map<int, int> App::DetectRes()
{
	int xPos = 0;
	int yPos = 0;

	int xRes = GetSystemMetrics(SM_CXSCREEN);
	int yRes = GetSystemMetrics(SM_CYSCREEN);


	if (xRes == 1920) 
	{
		xPos = 20;
		yPos = 700;
	}
	else 
	{
		xPos = 40;
		yPos = 1000;
	}
	std::map<int, int> res{ { xPos, yPos } };

	return res;
}

bool App::OnInit()
{
	auto res = DetectRes();

	mainframe = new MainFrame(res.begin()->first, res.begin()->second);
	mainframe->Show();

	return true;
}
