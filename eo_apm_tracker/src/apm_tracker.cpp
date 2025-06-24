
#include "apm_tracker.h"

HHOOK ApmTracker::keyboard_hook = NULL;
HHOOK ApmTracker::mouse_hook = NULL;
std::mutex ApmTracker::m;
std::vector<int> ApmTracker::actions_per_second;
int ApmTracker::current_apm = 0;

ApmTracker::ApmTracker()
{
	actions_per_second.push_back(0);
	this->rolling_actions = 0;
	this->m_running = true;
}

ApmTracker::~ApmTracker()
{

}

void ApmTracker::Start()
{
	SetHooks();
	t = std::thread(&ApmTracker::Tick, this);
}

void ApmTracker::Stop()
{
	m_running = false;
	RemoveHooks();
	if (t.joinable())
	{
		t.join();
	}
}

void ApmTracker::Tick()
{
	while (m_running)
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
	if(!actions_per_second.empty())
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
	if (nCode >= 0 && (wParam == WM_KEYUP || wParam == WM_SYSKEYUP))
		AddAction();

	return(CallNextHookEx(NULL, nCode, wParam, lParam));
}

LRESULT CALLBACK ApmTracker::MouseProc(int nCode, WORD wParam, LONG lParam)
{
	if (nCode >= 0 && (
		wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP ||
		wParam == WM_MBUTTONUP || wParam == WM_XBUTTONUP))
	{
		AddAction();
	}

	return(CallNextHookEx(NULL, nCode, wParam, lParam));
}