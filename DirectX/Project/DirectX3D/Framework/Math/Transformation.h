#pragma once

class Transformation
{
public:
	Transformation();
	~Transformation() = default;

	void Update();
	virtual void GUIRender();

	Vector3 GetRightVector() const { return Right.GetNormalize(); }
	Vector3 GetUpVector() const { return Up.GetNormalize(); }
	Vector3 GetForwardVector() const { return Forward.GetNormalize(); }

	Vector3 GetGlobalLocation() { return GlobalLocation; }
	Vector3 GetGlobalScale() { return GlobalScale; }

	Transformation* GetParentTransform() { return Parent; }
	Transformation* GetTopParentTransform();
	Matrix GetWorldMatrix() { return World; }

	void AttachTransform(Transformation* transform) { Parent = transform; }
	void SetPivot(Vector3 Pivot) { this->Pivot = Pivot; }
	const Vector3& GetPivot() const { return Pivot; }

	void SetActive(const bool value) { Active = value; }
	const bool IsActive() const { return Active; }
	
	void SetTag(const string Tag) { this->Tag = Tag; }
	const string GetTag() const { return Tag; }

	const Vector3& GetLocalLocation() const { return Location; }
	const Vector3& GetLocalRotation() const { return Rotation; }
	const Vector3& GetLocalScale() const { return Scale; }

	void SetLocalLocation(const Vector3 value) { Location = value; }
	void SetLocalRotation(const Vector3 value) { Rotation = value; }
	void SetLocalScale(const Vector3 value) { Scale = value; }

	void AddLocalLocation(const Vector3 value) { Location += value; }
	void AddLocalRotation(const Vector3 value) { Rotation += value; }
	void AddLocalScale(const Vector3 value) { Scale += value; }

	void Save();
	void Load();

	void SetWorld(const Matrix World) { this->World = World; }

protected:
	string Tag;

	///////////////////////////////////////////////////////////////////////////
	// Local
	///////////////////////////////////////////////////////////////////////////
	Vector3 Location = { 0.0, 0.0, 0.0 };
	Vector3 Rotation = { 0.0, 0.0, 0.0 };
	Vector3 Scale = { 1.0, 1.0, 1.0 };
	///////////////////////////////////////////////////////////////////////////

	bool Active = true;
	Matrix World;

private:
	Transformation* Parent = nullptr;

	Vector3 Pivot;
	Vector3 Right, Up, Forward;
	Vector3 GlobalLocation, GlobalScale;

	XMFLOAT4X4 WorldMatrix;
};