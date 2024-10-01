#pragma once

#include <wx/wx.h>
#include <wx/timer.h>
#include "../apm/apm_tracker.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(int xPos, int yPos);
	~MainFrame();
	void UpdateFrame(wxTimerEvent& ev);

private:
	ApmTracker* tracker = nullptr;
	std::thread t;

	wxTimer* timer = nullptr;
	wxStaticText* apm_text = nullptr;
};