
#include "main.h"

int APMTracker::current_apm = 0;

Main::Main(int xPos, int yPos) : wxFrame(nullptr, wxID_ANY, "eo_apm_tracker", wxPoint(xPos, yPos), wxSize(100, 40), wxSTAY_ON_TOP)
{
	this->tracker = new APMTracker();
	t = std::thread(&APMTracker::Run, tracker);

	apm_text = new wxStaticText(this, wxID_ANY, (wxString::Format(wxT("%i APM"), 0)), wxPoint(5, 5));

	wxFont font(16, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	this->apm_text->SetFont(font);
	this->apm_text->SetForegroundColour(wxColour(160, 0, 0));

	this->timer = new wxTimer(this);
	Bind(wxEVT_TIMER, &Main::UpdateFrame, this);
	timer->Start(1000);
}
Main::~Main()
{
	t.join();
	delete tracker;
}

void Main::UpdateFrame(wxTimerEvent& ev)
{
	this->apm_text->SetLabel(wxString::Format(wxT("%i APM"), tracker->GetAPM()));
}