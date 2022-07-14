#pragma once

#include <Windows.h>
#include <thread>
#include <mutex>

class APMTracker
{
public:
	APMTracker(const APMTracker&) = delete;

	~APMTracker();

	static APMTracker& Initialise()
	{
		return tracker_instance;
	}

	void Run();

	static LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
	{
		APMTracker t;
		switch (wParam)
		{
		case WM_KEYDOWN:
			t.SetAPM(1);
		}

		return CallNextHookEx(NULL, nCode, wParam, lParam);
	}

	void SetAPM(int apm);
	int GetAPM();

private:
	APMTracker() {}

	static APMTracker tracker_instance;
	
	void Listener();

	std::thread t;

	int apm = 10;
};

