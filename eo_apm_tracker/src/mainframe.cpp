
#include "mainframe.h"
#include "app.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_TIMER(wxID_ANY, MainFrame::UpdateFrame)
EVT_CLOSE(MainFrame::OnClose)
wxEND_EVENT_TABLE()

int ApmTracker::current_apm = 0;

MainFrame::MainFrame(int xPos, int yPos) : wxFrame(nullptr, wxID_ANY, "eo_apm_tracker", wxPoint(xPos, yPos), wxSize(100, 40), wxSTAY_ON_TOP)
{
	this->tracker = new ApmTracker();
	t = std::thread(&ApmTracker::Run, tracker);

	apm_text = new wxStaticText(this, wxID_ANY, (wxString::Format(wxT("%i APM"), 0)), wxPoint(5, 5));

	wxFont font(16, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	this->apm_text->SetFont(font);
	this->apm_text->SetForegroundColour(wxColour(160, 0, 0));

	this->timer = new wxTimer(this);
	Bind(wxEVT_TIMER, &MainFrame::UpdateFrame, this);
	timer->Start(1000);
}
MainFrame::~MainFrame()
{
	t.join();
	delete tracker;
}

void MainFrame::UpdateFrame(wxTimerEvent& ev)
{
	this->apm_text->SetLabel(wxString::Format(wxT("%i APM"), tracker->GetAPM()));
}

void MainFrame::OnClose(wxCloseEvent& event)
{
	wxGetApp().StopMainLoop();
	event.Skip();
}
