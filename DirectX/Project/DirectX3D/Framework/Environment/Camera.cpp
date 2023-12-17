#include "Framework.h"

Camera::Camera()
{
	Transform.SetTag("Camera");

	View = new ViewBuffer();
	View->SetVS(1);

	PreMousePos = GameInstance::GetMousePos();
	GameInstance::SetMousePos(Vector2(CENTER_X, CENTER_Y));
}

Camera::~Camera()
{
	delete View;
}

void Camera::Update()
{
	
}

void Camera::GUIRender()
{
}

void Camera::SetView()
{
}

Vector3 Camera::ScreenToWorld(Vector3 Pos)
{
	return Vector3();
}

Vector3 Camera::WorldToScreen(Vector3 Pos)
{
	return Vector3();
}

void Camera::SetOwner(Transformation* Owner)
{
}
