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
	static HHOOK keyboard;
	static void SetHooks(void);
	static void RemoveHooks(void);
	static LRESULT CALLBACK KeyboardHook(int, WORD, LONG);

	std::thread t;
	void Tick();

	static void SetAPM(int apm);

	static int current_apm;
	static std::vector<int> apm;
};

