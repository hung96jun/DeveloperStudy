#include "Framework.h"
#include "SamplerState.h"

SamplerState::SamplerState()
{
	Desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	Desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	Desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	Desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	Desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	Desc.MinLOD = 0;
	Desc.MaxLOD = D3D11_FLOAT_TO_SRGB_EXPONENT_NUMERATOR;

	Changed();
}

SamplerState::~SamplerState()
{
	State->Release();
}

void SamplerState::SetState(UINT Slot)
{
	DC->PSSetSamplers(Slot, 1, &State);
}

void SamplerState::Filter(D3D11_FILTER Value)
{
	Desc.Filter = Value;
	Changed();
}

void SamplerState::Changed()
{
	if (State != nullptr)
		State->Release();

	DEVICE->CreateSamplerState(&Desc, &State);
}
