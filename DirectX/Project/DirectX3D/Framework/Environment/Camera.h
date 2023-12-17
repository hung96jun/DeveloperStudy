#pragma once

class Camera
{
public:
	Camera();
	~Camera();

	void Update();
	void GUIRender();

	void SetView();
	void SetTarget(Transformation* Target) { this->Target = Target; }

	Vector3 ScreenToWorld(Vector3 Pos);
	Vector3	WorldToScreen(Vector3 Pos);

	void SetDistance(float Value) { Distance = Value; }
	void SetHeight(float Value) { Height = Value; }

	const Transformation& GetTransform() const { return Transform; }
	void SetOwner(Transformation* Owner);

private:
	ViewBuffer* View;
	Matrix ViewMatrix;
	Matrix Projection;

	float MoveSpeed = 70.0f;
	float RotSpeed = 1.0f;

	bool isFreeMode = false;

	Vector2 PreMousePos;

	Transformation* Target = nullptr;

	float Distance = 20.0f;
	float Height = 20.0f;
	float MoveDamping = 5.0f;
	float RotDamping = 1.0f;

	float DestRot = 0.0f;
	Vector3 DestPos = Vector3::ZeroVector();
	Vector3 FocusOffset = Vector3::ZeroVector();

	bool isLookAttarget = true;
	bool isLookatTargetX = true;
	bool isLookAtTargetY = true;

	Matrix RotMatrix;

	bool isFPS = false;

	Vector2 ClientCenter = { (double)(WIN_WIDTH >> 1), (double)(WIN_HEIGHT >> 1)};

	Transformation Transform;
};

