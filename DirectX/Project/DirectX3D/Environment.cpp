#include "Framework.h"

Environment::Environment()
{
	CreateProjection();
	CreateState();

	MainCamera = new Camera();
	LightB = new LightBuffer();
	UIViewB = new ViewBuffer();
}

Environment::~Environment()
{
	delete ProjectionB;
	delete LightB;
	delete UIViewB;

	delete MainCamera;

	delete Sampler;
	delete Rasterizer[0];
	delete Rasterizer[1];
	delete Blend[0];
	delete Blend[1];
}

void Environment::Update()
{
	if (KEY_DOWN(VK_F1) == true)
		bWireFrameMode = !bWireFrameMode;
	if (KEY_DOWN(VK_F2) == true)
	{
		// TODO : Collider Render Mode
	}

	MainCamera->Update();
}

void Environment::GUIRender()
{
}

void Environment::Set()
{
	SetViewport();
	SetPerspective();

	if (bWireFrameMode == false)
		Rasterizer[0]->SetState();
	else
		Rasterizer[1]->SetState();

	Blend[0]->SetState();
	LightB->SetPS(0);
}

void Environment::PostSet()
{
	UIViewB->SetVS(1);
	SetOrthographic();

	Blend[1]->SetState();
}

void Environment::SetViewport(UINT Width, UINT Height)
{
	ViewPort.Width = (FLOAT)Width;
	ViewPort.Height = (FLOAT)Height;
	ViewPort.MinDepth = 0.0f;
	ViewPort.MaxDepth = 1.0f;
	ViewPort.TopLeftX = 0.0f;
	ViewPort.TopLeftY = 0.0f;

	DC->RSSetViewports(1, &ViewPort);
}

void Environment::SetPerspective()
{
	ProjectionB->Set(Perspective);
	ProjectionB->SetVS(2);
}

void Environment::SetOrthographic()
{
	ProjectionB->Set(Orthgraphic);
	ProjectionB->SetVS(2);
}

void Environment::CreateProjection()
{
	Orthgraphic = XMMatrixOrthographicOffCenterLH(
		0.0f, WIN_WIDTH, 0.0f, WIN_HEIGHT, -1.0f, 1.0f
	);

	Perspective = XMMatrixPerspectiveFovLH(XM_PIDIV4,
		(float)WIN_WIDTH / (float)WIN_HEIGHT, NearZ, FarZ
	);

	ProjectionB = new MatrixBuffer();
}

void Environment::CreateState()
{
	Sampler = new SamplerState();
	Sampler->SetState();

	Rasterizer[0] = new RasterizerState();
	Rasterizer[1] = new RasterizerState();
	Rasterizer[1]->FillMode(D3D11_FILL_WIREFRAME);

	Blend[0] = new BlendState();
	Blend[1] = new BlendState();
	Blend[1]->Alpha(true);
}
