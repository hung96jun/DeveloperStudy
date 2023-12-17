#include "Framework.h"

BlendState::BlendState()
{
	Desc.RenderTarget[0].BlendEnable = false;
	Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	Desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

	Desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_SRC_ALPHA;
	Desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
	Desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	Desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	Changed();
}

BlendState::~BlendState()
{
	State->Release();
}

void BlendState::SetState()
{
	float blendFactor[4] = {};
	DC->OMSetBlendState(State, blendFactor, 0xffffffff);
}

void BlendState::Alpha(bool Value)
{
	Desc.RenderTarget[0].BlendEnable = Value;
	Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	Desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

	Changed();
}

void BlendState::Additive()
{
	Desc.RenderTarget[0].BlendEnable = true;
	Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

	Changed();
}

void BlendState::AlphaToConverage(bool Value)
{
	Desc.AlphaToCoverageEnable = Value;
	Changed();
}

void BlendState::Changed()
{
	if (State != nullptr)
		State->Release();

	DEVICE->CreateBlendState(&Desc, &State);
}
