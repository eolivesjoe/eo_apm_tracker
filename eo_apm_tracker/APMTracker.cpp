
#include "APMTracker.h"

APMTracker::APMTracker()
{
}

APMTracker::~APMTracker()
{
}

void APMTracker::Run()
{
	while (1)
	{
		if (GetKeyState(VK_SHIFT) & 0x8000)
		{
			++apm;
			Sleep(100);
		}
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
