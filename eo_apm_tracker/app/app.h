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
	virtual bool IsMainLoopStopped();
	virtual void StopMainLoop();

private:
	MainFrame* mainframe = nullptr;
	bool stop_main_loop = false;

};

wxDECLARE_APP(App);