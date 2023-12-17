#include "Framework.h"

Transformation::Transformation()
{
	Pivot = Vector3(0.0);
	Scale = Vector3(1.0);
	Rotation = Vector3(0.0);
	Location = Vector3(0.0);

	World = XMMatrixIdentity();
}

void Transformation::Update()
{
	World = XMMatrixTransformation(Pivot.GetValue(),
		XMQuaternionIdentity(), Scale.GetValue(), Pivot.GetValue(),
		XMQuaternionRotationRollPitchYawFromVector(Rotation.GetValue()),
		Location.GetValue());

	if (Parent != nullptr)
		World *= Parent->World;

	XMStoreFloat4x4(&WorldMatrix, World);
	Right = Vector3(WorldMatrix._11, WorldMatrix._12, WorldMatrix._13);
	Up = Vector3(WorldMatrix._21, WorldMatrix._22, WorldMatrix._23);
	Forward = Vector3(WorldMatrix._31, WorldMatrix._32, WorldMatrix._33);

	XMVECTOR s, r, l;
	XMMatrixDecompose(&s, &r, &l, World);

	Float3 tempLocation, tempScale;
	XMStoreFloat3(&tempLocation, l);
	XMStoreFloat3(&tempScale, s);

	GlobalLocation = tempLocation;
	GlobalScale = tempScale;
}

void Transformation::GUIRender()
{
}

Transformation* Transformation::GetTopParentTransform()
{
	if (Parent != nullptr)
		return Parent->GetTopParentTransform();

	return this;
}

void Transformation::Save()
{
}

void Transformation::Load()
{
}
