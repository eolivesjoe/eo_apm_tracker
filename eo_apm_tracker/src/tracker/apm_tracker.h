#pragma once

#include <Windows.h>
#include <thread>
#include <mutex>
#include <vector>

namespace tracker
{
	class ApmTracker
	{
	public:
		ApmTracker();
		~ApmTracker();

		void start();
		void stop();
		void resetSession();

		static int getAPM();

	private:
		static HHOOK m_keyboard_hook;
		static HHOOK m_mouse_hook;
		static void setHooks(void);
		static void removeHooks(void);
		static LRESULT CALLBACK keyboardProc(int nCode, WORD wParam, LONG lParam);
		static LRESULT CALLBACK mouseProc(int nCode, WORD wParam, LONG lParam);

		void tick();
		void incrementSecond();
		static void addAction();
		int calculateAPM();
		static void setAPM(int apm);

		std::thread t;

		static std::mutex m_lock;
		static std::vector<int> m_actions_per_second;
		const int m_apm_window = 60;
		static int m_current_apm;
		int m_rolling_actions;
		std::atomic<bool> m_running;
	};
} // namespace tracker