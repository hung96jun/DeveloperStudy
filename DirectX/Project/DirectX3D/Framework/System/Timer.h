#pragma once

class Timer
{
private:
	const float EPSILON = 0.01f;

public:
	Timer();
	~Timer();

	void Update();
	
	void SetDeltaScale(const float Value) { DeltaScale = Value; }
	void SetLockFPS(int Value) { LockFPS = Value; }

	const float GetElapsedTime()
	{
		return ElapsedTime > EPSILON ? EPSILON : ElapsedTime * DeltaScale;
	}
	const int GetFPS() const { return FrameRate; }

private:
	float TimeScale = 0.0f;
	float ElapsedTime = 0.0f;
	float OneSecCount = 0.0f;
	float DeltaScale = 1.0f;

	__int64 Curtime = 0;
	__int64 LastTime = 0;
	__int64 PeriodFrequency = 0;

	int FrameRate = 0;
	int FrameCount = 0;
	int LockFPS = 60;
};

