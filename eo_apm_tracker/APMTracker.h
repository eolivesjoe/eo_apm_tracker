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

	void Tick();
	void IncrementSecond();
	static void AddAction();
	static void SetAPM(int apm);

	std::thread t;
	static int current_apm;
	static std::vector<int> actions_per_second;
};

/*
var apm_window = 60
rolling_apm = 0

	rolling_apm = current_apm + next second - aps[curr sec - window]?
*/

