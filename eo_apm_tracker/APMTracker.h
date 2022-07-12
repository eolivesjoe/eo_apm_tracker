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
	void Tick();

	void SetAPM(int apm);
	int GetAPM();

private:
	bool thread_state = false;
	bool thread_error = false;

	int apm = 0;
};

