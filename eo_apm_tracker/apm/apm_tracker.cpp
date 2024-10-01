
#include "apm_tracker.h"

HHOOK ApmTracker::keyboard_hook = NULL;
HHOOK ApmTracker::mouse_hook = NULL;
std::mutex ApmTracker::m;
std::vector<int> ApmTracker::actions_per_second;

ApmTracker::ApmTracker()
{
	this->rolling_actions = 0;
}

ApmTracker::~ApmTracker()
{
	t.join();
}

void ApmTracker::Run()
{
	SetHooks();
	MSG message = { };

	t = std::thread(&ApmTracker::Tick, this);

	while (GetMessage(&message, NULL, NULL, NULL) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	RemoveHooks();
}

void ApmTracker::Tick()
{
	while (1)
	{
		IncrementSecond();
		Sleep(1000);
	}
}

void ApmTracker::IncrementSecond()
{
	int calculated_apm = CalculateAPM();

	const std::lock_guard<std::mutex> lock(m);
	SetAPM(calculated_apm);
	actions_per_second.push_back(0);
}

void ApmTracker::AddAction()
{
	const std::lock_guard<std::mutex> lock(m);
	++actions_per_second[actions_per_second.size() - 1];
}

int ApmTracker::CalculateAPM()
{
	int current_second = actions_per_second.size() - 1;

	if (current_second < 1)
		return 0;

	rolling_actions += actions_per_second[current_second];
	if (actions_per_second.size() > apm_window)
	{
		rolling_actions -= actions_per_second[current_second - apm_window];
		return rolling_actions;
	}
	float apm = static_cast<float>(apm_window) / static_cast<float>(current_second);
	return static_cast<int>(apm * rolling_actions);
}

void ApmTracker::SetAPM(int new_apm)
{
	current_apm = new_apm;
}

int ApmTracker::GetAPM()
{
	return current_apm;
}

void ApmTracker::SetHooks(void)
{
	keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyboardProc, 0, 0);
	mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)MouseProc, 0, 0);
}

void ApmTracker::RemoveHooks(void)
{
	UnhookWindowsHookEx(keyboard_hook);
	UnhookWindowsHookEx(mouse_hook);
}

LRESULT CALLBACK ApmTracker::KeyboardProc(int nCode, WORD wParam, LONG lParam)
{
	if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		AddAction();

	return(CallNextHookEx(mouse_hook, nCode, wParam, lParam));
}

LRESULT CALLBACK ApmTracker::MouseProc(int nCode, WORD wParam, LONG lParam)
{
	if (wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP ||
		wParam == WM_MBUTTONUP || wParam == WM_XBUTTONUP)
		AddAction();

	return(CallNextHookEx(keyboard_hook, nCode, wParam, lParam));
}