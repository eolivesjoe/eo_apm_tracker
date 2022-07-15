
#include "APMTracker.h"

HHOOK APMTracker::keyboard_hook = NULL;
HHOOK APMTracker::mouse_hook = NULL;

APMTracker::APMTracker()
{
}

APMTracker::~APMTracker()
{
}

void APMTracker::Run()
{
	SetHooks();
	MSG message = { };

	t = std::thread(&APMTracker::Tick, this);

	while (GetMessage(&message, NULL, NULL, NULL) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	t.join();
	RemoveHooks();
}

void APMTracker::Tick()
{
	while (1)
	{
		// increment second
		Sleep(1000);
	}
}

void APMTracker::SetAPM(int new_apm)
{
	current_apm = new_apm;
}

int APMTracker::GetAPM()
{
	return current_apm;
}

void APMTracker::SetHooks(void)
{
	keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyboardProc, 0, 0);
	mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)MouseProc, 0, 0);
}

void APMTracker::RemoveHooks(void)
{
	UnhookWindowsHookEx(keyboard_hook);
	UnhookWindowsHookEx(mouse_hook);
}

LRESULT CALLBACK APMTracker::KeyboardProc(int nCode, WORD wParam, LONG lParam)
{
	if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		SetAPM(GetAPM() + 1);
	// add action to vector[curr sec] 

	// call mouse hook?
	return(CallNextHookEx(mouse_hook, nCode, wParam, lParam));
}

LRESULT CALLBACK APMTracker::MouseProc(int nCode, WORD wParam, LONG lParam)
{
	if (wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP ||
		wParam == WM_MBUTTONUP)
		SetAPM(GetAPM() + 1);

	return(CallNextHookEx(keyboard_hook, nCode, wParam, lParam));
}