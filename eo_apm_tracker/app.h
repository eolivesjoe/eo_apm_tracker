#pragma once

#include <wx/wx.h>
#include <map>
#include "Main.h"

class App : public wxApp
{
public:
	App();
	~App();

	std::map<int, int> DetectRes();

	virtual bool OnInit();

private:
	Main* main_frame = nullptr;

};

