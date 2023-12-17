#include "Framework.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (auto scene : Scenes)
		delete scene.second;
}

void SceneManager::PreUpdate()
{
	for (Scene* scene : CurScenes)
		scene->PreUpdate();
}

void SceneManager::Update()
{
	for (Scene* scene : CurScenes)
		scene->Update();
}

void SceneManager::PostUpdate()
{
	for (Scene* scene : CurScenes)
		scene->PostUpdate();
}

void SceneManager::PreRender()
{
	for (Scene* scene : CurScenes)
		scene->PreRender();
}

void SceneManager::Render()
{
	for (Scene* scene : CurScenes)
		scene->Render();
}

void SceneManager::PostRender()
{
	for (Scene* scene : CurScenes)
		scene->PostRender();
}

void SceneManager::UIRender()
{
	for (Scene* scene : CurScenes)
		scene->UIRender();
}

void SceneManager::GUIRender()
{
	for (Scene* scene : CurScenes)
		scene->GUIRender();
}

void SceneManager::Create(const string Key, Scene* NewScene)
{
	if (Scenes.count(Key) > 0)
		return;
	Scenes[Key] = NewScene;
}

Scene* SceneManager::Add(const string Key)
{
	if (Scenes.count(Key) == 0)
		return nullptr;

	list<Scene*>::iterator findScene = find(CurScenes.begin(), CurScenes.end(), Scenes[Key]);
	if (findScene != CurScenes.end())
		return Scenes[Key];

	CurScenes.push_back(Scenes[Key]);
	CurScenes.back()->Start();

	return Scenes[Key];
}

void SceneManager::Remove(const string Key)
{
	if (Scenes.count(Key) == 0)
		return;

	list<Scene*>::iterator findScene = find(CurScenes.begin(), CurScenes.end(), Scenes[Key]);
	if (findScene != CurScenes.end())
		return;

	Scenes[Key]->End();
	CurScenes.erase(findScene);
}
