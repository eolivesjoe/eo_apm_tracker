#pragma once

#include <wx/wx.h>
#include <wx/timer.h>
#include "APMTracker.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();
	void UpdateFrame(wxTimerEvent& ev);
	int apm_counter = 0;

private:
	wxTimer* timer = nullptr;
	wxStaticText* apm_text = nullptr;
};




