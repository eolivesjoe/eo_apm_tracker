#pragma once

#include <Windows.h>
#include <thread>

class APMTracker
{
public:
	APMTracker();
	~APMTracker();

	void Run();
	void SetAPM(int apm);
	int GetAPM();

private:
	bool thread_state = false;
	bool thread_error = false;

	int apm = 0;
};

