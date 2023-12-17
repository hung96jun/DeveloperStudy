#pragma once

class Environment
{
public:
	Environment();
	~Environment();

	void Update();
	void GUIRender();

	void Set();
	void PostSet();

	void SetViewport(UINT Width = WIN_WIDTH, UINT Height = WIN_HEIGHT);
	void SetPerspective();
	void SetOrthographic();

	Camera* GetMainCamera() { return MainCamera; }
	const Matrix& GetProjection() { return Perspective; }

private:
	void CreateProjection();
	void CreateState();

private:
	MatrixBuffer* ProjectionB;
	LightBuffer* LightB;

	ViewBuffer* UIViewB;

	SamplerState* Sampler;
	RasterizerState* Rasterizer[2];
	BlendState* Blend[2];

	Camera* MainCamera;

	D3D11_VIEWPORT ViewPort;

	bool bWireFrameMode = false;

	Matrix Perspective;
	Matrix Orthgraphic;

	float NearZ = 0.1f;
	float FarZ = 1000.0f;
};

