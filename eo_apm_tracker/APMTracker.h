#pragma once

#include <Windows.h>
#include <thread>
#include <mutex>

class APMTracker
{
public:
	APMTracker();

	~APMTracker();

	void Run();

	static int GetAPM();

private:
	static HHOOK keyboard;
	static void SetHook(void);
	static void RemoveHook(void);
	static LRESULT CALLBACK KeyboardHook(int, WORD, LONG);

	static void SetAPM(int apm);

	static int current_apm;
};

