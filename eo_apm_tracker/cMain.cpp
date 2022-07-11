#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "eo window", wxPoint(1820, 50), wxSize(80, 30), wxSTAY_ON_TOP)
{
	m_text1 = new wxStaticText(this, wxID_ANY, "tester2");
}
cMain::~cMain()
{
}
