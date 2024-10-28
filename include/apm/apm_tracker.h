#pragma once

#include <Windows.h>
#include <thread>
#include <mutex>
#include <vector>

class ApmTracker
{
public:
	ApmTracker();
	~ApmTracker();

	void Run();
	static int GetAPM();

private:

	// Functions for registering keyboard and mouse actions.
	static HHOOK keyboard_hook;
	static HHOOK mouse_hook;
	static void SetHooks(void);
	static void RemoveHooks(void);
	static LRESULT CALLBACK KeyboardProc(int nCode, WORD wParam, LONG lParam);
	static LRESULT CALLBACK MouseProc(int nCode, WORD wParam, LONG lParam);

	void Tick();
	void IncrementSecond();
	static void AddAction();
	int CalculateAPM();
	static void SetAPM(int apm);

	std::thread t;

	static std::mutex m;
	static std::vector<int> actions_per_second;
	const int apm_window = 60;
	static int current_apm;
	int rolling_actions;
};