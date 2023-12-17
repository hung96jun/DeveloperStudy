#include "Framework.h"

Timer::Timer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&PeriodFrequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&LastTime);

	TimeScale = 1.0f / (float)PeriodFrequency;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&Curtime);
	ElapsedTime = (float)(Curtime - LastTime) * TimeScale;

	while (ElapsedTime < (1.0f / LockFPS))
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&Curtime);
		ElapsedTime = (float)(Curtime - LastTime) * TimeScale;
	}

	LastTime = Curtime;

	++FrameCount;
	OneSecCount += ElapsedTime;

	if (OneSecCount >= 1.0f)
	{
		FrameRate = FrameCount;
		FrameCount = 0;
		OneSecCount = 0.0f;
	}
}
