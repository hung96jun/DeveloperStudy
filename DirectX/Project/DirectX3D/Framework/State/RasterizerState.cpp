#include "Framework.h"

RasterizerState::RasterizerState()
{
	Desc.CullMode = D3D11_CULL_BACK;
	Desc.FillMode = D3D11_FILL_SOLID;

	Changed();
}

RasterizerState::~RasterizerState()
{
	State->Release();
}

void RasterizerState::SetState()
{
	DC->RSSetState(State);
}

void RasterizerState::FillMode(D3D11_FILL_MODE Value)
{
	Desc.FillMode = Value;

	Changed();
}

void RasterizerState::FrontCounterClockwise(bool Value)
{
	Desc.FrontCounterClockwise = Value;

	Changed();
}

void RasterizerState::Changed()
{
	if (State != nullptr)
		State->Release();

	DEVICE->CreateRasterizerState(&Desc, &State);
}
