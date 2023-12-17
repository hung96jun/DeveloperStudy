#pragma once

class MatrixBuffer : public ConstBuffer
{
public:
	MatrixBuffer() : ConstBuffer(&Procesion, sizeof(Matrix))
	{
		Procesion = XMMatrixIdentity();
	}

	void Set(Matrix Value)
	{
		Procesion = XMMatrixTranspose(Value);
	}
	
private:
	Matrix Procesion;
};

class Worldbuffer : public ConstBuffer
{
private:
	struct WorldData
	{
		Matrix World = XMMatrixIdentity();
		int Type = 0;
		float Padding[3];
	};

public:
	Worldbuffer() : ConstBuffer(&Data, sizeof(WorldData))
	{
	}

	void Set(Matrix Value)
	{
		Data.World = XMMatrixTranspose(Value);
	}

	void SetType(int Type)
	{
		Data.Type = Type;
	}
	
private:
	WorldData Data;
};

class ViewBuffer : public ConstBuffer
{
private:
	struct ViewData
	{
		Matrix View;
		Matrix InvView;
	};

public:
	ViewBuffer() : ConstBuffer(&Data, sizeof(ViewData))
	{
		Data.View = XMMatrixIdentity();
		Data.InvView = XMMatrixIdentity();
	}

	void Set(Matrix View, Matrix InvView)
	{
		Data.View = XMMatrixTranspose(View);
		Data.InvView = XMMatrixTranspose(InvView);
	}

private:
	ViewData Data;
};

class ColorBuffer : public ConstBuffer
{
public:
	ColorBuffer() : ConstBuffer(&Color, sizeof(Float4))
	{
	}

	Float4& Get() { return Color; }

private:
	Float4 Color = { 1.0f, 1.0f, 1.0f, 1.0f };
};

class IntValueBuffer : public ConstBuffer
{
public:
	IntValueBuffer() : ConstBuffer(Values, sizeof(int) * 4)
	{
	}

	int* Get() { return Values; }

private:
	int Values[4] = {};
};

class FloatValueBuffer : public ConstBuffer
{
public:
	FloatValueBuffer() : ConstBuffer(Values, sizeof(float) * 4)
	{
	}

	float* Get() { return Values; }

private:
	float Values[4] = {};
};

class LightBuffer : public ConstBuffer
{
private:
	struct Light
	{
		Float4 Color = { 1.0f, 1.0f, 1.0f, 1.0f };
		Float3 Direction = { 0.0f, -1.0f, 1.0f };
		float Shininess = 24.0f;
	};

	struct LightData
	{
		Light Lights[MAX_LIGHT];

		UINT LightCount = 1;
		Float3 AmbientLight = { 0.1f, 0.1f, 0.1f };
		Float3 AmvientCeil = { 0.1f, 0.1f, 0.1f };
		float Padding;
	};

public:
	LightBuffer() : ConstBuffer(&Data, sizeof(LightData))
	{
	}

	LightData& Get() { return Data; }

private:
	LightData Data;
};