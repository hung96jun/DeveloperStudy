#pragma once
#include "Scene.h"
class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	void PreUpdate() override;
	void Update() override;
	void PostUpdate() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
	void GUIRender() override;


};

