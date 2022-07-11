#pragma once

#include <wx/wx.h>
#include "Main.h"

class App : public wxApp
{
public:
	App();
	~App();

	virtual bool OnInit();

private:
	Main* main_frame = nullptr;
};

