#include "Framework.h"

#include "Scenes/TestScene.h"

GameManager::GameManager()
{
	Create();
	Init();

	GameInstance::GetSceneManager()->Create("Test", new TestScene());
}

GameManager::~GameManager()
{
	Delete();
}

void GameManager::Update()
{
	GameInstance::GetKeyboard()->Update();
	GameInstance::GetTimer()->Update();

	GameInstance::GetSceneManager()->PreUpdate();
	GameInstance::GetSceneManager()->Update();
	GameInstance::GetSceneManager()->PostUpdate();

}

void GameManager::Render()
{
	GameInstance::GetSceneManager()->PreRender();

	GameInstance::GetDevice()->Clear();

	GameInstance::GetSceneManager()->Render();
	GameInstance::GetSceneManager()->PostRender();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	GameInstance::GetSceneManager()->UIRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	GameInstance::GetDevice()->Present();
}

void GameManager::Init()
{
}

void GameManager::Create()
{

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(DEVICE, DC);
}

void GameManager::Delete()
{

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();
}
