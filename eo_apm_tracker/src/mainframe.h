#pragma once

#include <wx/wx.h>
#include <wx/timer.h>
#include "apm_tracker.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(int xPos, int yPos);
	~MainFrame();
	void UpdateFrame(wxTimerEvent& ev);
	void OnClose(wxCloseEvent& event);

private:

	ApmTracker* tracker = nullptr;
	std::thread t;

	wxTimer* timer = nullptr;
	wxStaticText* apm_text = nullptr;

	wxDECLARE_EVENT_TABLE();
};