#include "App.h"

wxIMPLEMENT_APP(App);

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
		xPos = 1840;
		yPos = 60;
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

	main_frame = new Main(res.begin()->first, res.begin()->second);
	main_frame->Show();

	return true;
}
