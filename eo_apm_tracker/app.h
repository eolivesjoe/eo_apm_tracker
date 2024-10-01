#pragma once

#include <wx/wx.h>
#include <map>
#include "mainframe.h"

class App : public wxApp
{
public:
	App();
	~App();

	std::map<int, int> DetectRes();

	virtual bool OnInit();

private:
	MainFrame* mainframe = nullptr;

};

