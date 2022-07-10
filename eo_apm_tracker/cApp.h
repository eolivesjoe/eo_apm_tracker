#pragma once

#include "wx/wx.h"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();

	virtual bool OnInit();
};

