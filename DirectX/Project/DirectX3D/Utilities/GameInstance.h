#pragma once

class GameInstance
{
public:
	GameInstance();
	~GameInstance();

	static Keyboard* GetKeyboard() { return Key; }
	static Timer* GetTimer() { return Time; }
	static Device* GetDevice() { return DeviceSystem; }
	static SceneManager* GetSceneManager() { return SceneManagement; }

	static void SetMousePos(const Vector2 Value) { MousePos = Value; }
	static const Vector2 GetMousePos() { return MousePos; }

private:
	static Keyboard* Key;
	static Timer* Time;
	static Device* DeviceSystem;
	static SceneManager* SceneManagement;

	static Vector2 MousePos;
};

