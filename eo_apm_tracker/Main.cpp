
#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "eo_apm_tracker", wxPoint(1840, 50), wxSize(70, 30), wxSTAY_ON_TOP)
{
	apm_text = new wxStaticText(this, wxID_ANY, wxString::Format(wxT("%i APM"), apm_counter), wxPoint(5, 5));
	this->timer = new wxTimer(this);
	Bind(wxEVT_TIMER, &Main::UpdateFrame, this);
	timer->Start(1000);
}
Main::~Main()
{
}

void Main::UpdateFrame(wxTimerEvent& ev)
{
	apm_counter = apm_counter + 1;
	this->apm_text->SetLabel(wxString::Format(wxT("%i APM"), apm_counter));
}