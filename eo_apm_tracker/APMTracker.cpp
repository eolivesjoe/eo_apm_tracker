
#include "APMTracker.h"

HHOOK APMTracker::keyboard_hook = NULL;
HHOOK APMTracker::mouse_hook = NULL;
std::mutex APMTracker::m;
std::vector<int> APMTracker::actions_per_second;

APMTracker::APMTracker()
{
	this->rolling_actions = 0;
}

APMTracker::~APMTracker()
{
	t.join();
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
	RemoveHooks();
}

void APMTracker::Tick()
{
	while (1)
	{
		IncrementSecond();
		Sleep(1000);
	}
}

void APMTracker::IncrementSecond()
{
	const std::lock_guard<std::mutex> lock(m);
	SetAPM(CalculateAPM());
	actions_per_second.push_back(0);
}

void APMTracker::AddAction()
{
	const std::lock_guard<std::mutex> lock(m);
	++actions_per_second[actions_per_second.size() - 1];
}

int APMTracker::CalculateAPM()
{
	if (actions_per_second.size() == 0)
	{
		return 0;
	}

	rolling_actions += actions_per_second[actions_per_second.size() - 1];
	if (actions_per_second.size() > apm_window)
	{
		rolling_actions -= actions_per_second[(actions_per_second.size() - 1) - apm_window];
		return rolling_actions;
	}
	return (rolling_actions / actions_per_second.size()) * apm_window;
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
		AddAction();

	return(CallNextHookEx(mouse_hook, nCode, wParam, lParam));
}

LRESULT CALLBACK APMTracker::MouseProc(int nCode, WORD wParam, LONG lParam)
{
	if (wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP ||
		wParam == WM_MBUTTONUP || wParam == WM_XBUTTONUP)
		AddAction();

	return(CallNextHookEx(keyboard_hook, nCode, wParam, lParam));
}