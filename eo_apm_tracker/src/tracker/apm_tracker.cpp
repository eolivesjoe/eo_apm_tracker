#include "apm_tracker.h"
#include "../constants.h"

namespace tracker
{
	HHOOK ApmTracker::m_keyboard_hook = NULL;
	HHOOK ApmTracker::m_mouse_hook = NULL;
	std::mutex ApmTracker::m_lock;
	std::vector<int> ApmTracker::m_actions_per_second;
	int ApmTracker::m_current_apm = 0;

	ApmTracker::ApmTracker()
	{
		m_actions_per_second.push_back(0);
		this->m_rolling_actions = 0;
		this->m_running = true;
	}

	ApmTracker::~ApmTracker()
	{

	}

	void ApmTracker::start()
	{
		setHooks();
		t = std::thread(&ApmTracker::tick, this);
	}

	void ApmTracker::stop()
	{
		m_running = false;
		removeHooks();
		if (t.joinable())
		{
			t.join();
		}
	}

	void ApmTracker::tick()
	{
		while (m_running)
		{
			incrementSecond();
			Sleep(1000);
		}
	}

	void ApmTracker::incrementSecond()
	{
		int calculated_apm = calculateAPM();

		const std::lock_guard<std::mutex> lock(m_lock);
		setAPM(calculated_apm);
		m_actions_per_second.push_back(0);

		if (m_actions_per_second.size() > MAX_HISTORY)
		{
			m_rolling_actions -= m_actions_per_second.front();
			m_actions_per_second.erase(m_actions_per_second.begin());
		}
	}

	void ApmTracker::addAction()
	{
		const std::lock_guard<std::mutex> lock(m_lock);
		if (!m_actions_per_second.empty())
		{
			++m_actions_per_second[m_actions_per_second.size() - 1];
		}
	}

	int ApmTracker::calculateAPM()
	{
		int current_second = m_actions_per_second.size() - 1;

		if (current_second < 1)
			return 0;

		m_rolling_actions += m_actions_per_second[current_second];
		if (m_actions_per_second.size() > m_apm_window)
		{
			m_rolling_actions -= m_actions_per_second[current_second - m_apm_window];
			return m_rolling_actions;
		}
		float apm = static_cast<float>(m_apm_window) / static_cast<float>(current_second);
		return static_cast<int>(apm * m_rolling_actions);
	}

	void ApmTracker::setAPM(int new_apm)
	{
		m_current_apm = new_apm;
	}

	int ApmTracker::getAPM()
	{
		return m_current_apm;
	}

	void ApmTracker::setHooks(void)
	{
		m_keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)keyboardProc, 0, 0);
		m_mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)mouseProc, 0, 0);
	}

	void ApmTracker::removeHooks(void)
	{
		UnhookWindowsHookEx(m_keyboard_hook);
		UnhookWindowsHookEx(m_mouse_hook);
	}

	LRESULT CALLBACK ApmTracker::keyboardProc(int nCode, WORD wParam, LONG lParam)
	{
		if (nCode >= 0 && (wParam == WM_KEYUP || wParam == WM_SYSKEYUP))
			addAction();

		return(CallNextHookEx(NULL, nCode, wParam, lParam));
	}

	LRESULT CALLBACK ApmTracker::mouseProc(int nCode, WORD wParam, LONG lParam)
	{
		if (nCode >= 0 && (
			wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP ||
			wParam == WM_MBUTTONUP || wParam == WM_XBUTTONUP))
		{
			addAction();
		}

		return(CallNextHookEx(NULL, nCode, wParam, lParam));
	}

	void ApmTracker::resetSession()
	{
		std::lock_guard<std::mutex> lock(m_lock);
		m_actions_per_second.clear();
		m_actions_per_second.push_back(0);
		m_rolling_actions = 0;
		m_current_apm = 0;
	}
}