
#include "APMTracker.h"

APMTracker::APMTracker()
{
}

APMTracker::~APMTracker()
{
}

void APMTracker::Run()
{
	this->thread_state = true;

	MSG msg = { };
	while (1)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1);
	}

	// unhook mouse and keyboard
	this->thread_state = false;
}

void APMTracker::Tick()
{
	while (1)
	{
		// increment a second in apm vector
		Sleep(1000);
	}
}

void APMTracker::SetAPM(int apm)
{
	this->apm = apm;
}

int APMTracker::GetAPM()
{
	return this->apm;
}
