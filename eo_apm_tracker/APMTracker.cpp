
#include "APMTracker.h"

APMTracker::~APMTracker()
{
	t.join();
}

void APMTracker::Run()
{
	t = std::thread(&APMTracker::Listener, this);
}

void APMTracker::Listener()
{
	HHOOK keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, &KeyboardHook, 0, 0);

	MSG msg = { };
	while (1)
	{
		while (GetMessage(&msg, NULL, NULL, NULL) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1000);
	}

	UnhookWindowsHookEx(keyboard_hook);
}

void APMTracker::SetAPM(int apm)
{
	this->apm = apm;
}

int APMTracker::GetAPM()
{
	return this->apm;
}
