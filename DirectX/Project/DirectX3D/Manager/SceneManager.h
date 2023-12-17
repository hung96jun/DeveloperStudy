#pragma once

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void PreUpdate();
	void Update();
	void PostUpdate();

	void PreRender();
	void Render();
	void PostRender();

	void UIRender();
	void GUIRender();

	void Create(const string Key, Scene* NewScene);

	Scene* Add(const string Key);
	void Remove(const string Key);

private:
	map<string, Scene*> Scenes;
	list<Scene*> CurScenes;
};

