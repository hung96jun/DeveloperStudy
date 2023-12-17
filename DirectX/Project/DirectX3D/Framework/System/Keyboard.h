#pragma once

class Keyboard
{
private:
	static const UINT KEY_MAX = 255;

	enum KeyState
	{
		NONE, DOWN, UP, PRESS
	};

public:
	Keyboard() = default;
	~Keyboard() = default;

	void Update();

	bool Down(UINT Key) { return MapState[Key] == DOWN; }
	bool Up(UINT Key) { return MapState[Key] == UP; }
	bool Press(UINT Key) { return MapState[Key] == PRESS; }

private:
	BYTE CurState[KEY_MAX] = {};
	BYTE OldState[KEY_MAX] = {};
	KeyState MapState[KEY_MAX] = {};
};

