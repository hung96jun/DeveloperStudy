#include "Framework.h"

Keyboard* GameInstance::Key = nullptr;
Timer* GameInstance::Time = nullptr;
Device* GameInstance::DeviceSystem = nullptr;
SceneManager* GameInstance::SceneManagement = nullptr;
Vector2 GameInstance::MousePos = Vector2();

GameInstance::GameInstance()
{
	Key = new Keyboard();
	Time = new Timer();
	DeviceSystem = new Device();
	SceneManagement = new SceneManager();
}

GameInstance::~GameInstance()
{
	delete Key;
	delete Time;
	delete DeviceSystem;
	delete SceneManagement;
}
