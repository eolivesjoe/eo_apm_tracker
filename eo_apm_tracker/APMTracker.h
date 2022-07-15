#pragma once

#include <Windows.h>
#include <thread>
#include <mutex>
#include <vector>

class APMTracker
{
public:
	APMTracker();

	~APMTracker();

	void Run();

	static int GetAPM();

private:
	static HHOOK keyboard_hook;
	static HHOOK mouse_hook;
	static void SetHooks(void);
	static void RemoveHooks(void);
	static LRESULT CALLBACK KeyboardProc(int nCode, WORD wParam, LONG lParam);
	static LRESULT CALLBACK MouseProc(int nCode, WORD wParam, LONG lParam);

	std::thread t;
	void Tick();

	static void SetAPM(int apm);

	static int current_apm;
	static std::vector<int> apm;
};

