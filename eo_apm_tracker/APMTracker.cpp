
#include "APMTracker.h"

HHOOK APMTracker::keyboard = NULL;

APMTracker::APMTracker()
{
}

APMTracker::~APMTracker()
{
}

void APMTracker::Run()
{
	SetHook();
	MSG message = { };

	while (GetMessage(&message, NULL, NULL, NULL) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	RemoveHook();
}

void APMTracker::SetAPM(int new_apm)
{
	current_apm = new_apm;
}

int APMTracker::GetAPM()
{
	return current_apm;
}

void APMTracker::SetHook(void)
{
	keyboard = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyboardHook, 0, 0);
}

void APMTracker::RemoveHook(void)
{
	UnhookWindowsHookEx(keyboard);
}

LRESULT CALLBACK APMTracker::KeyboardHook(int nCode, WORD wParam, LONG lParam)
{
	if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		SetAPM(GetAPM() + 1);

	return(CallNextHookEx(NULL, nCode, wParam, lParam));
}