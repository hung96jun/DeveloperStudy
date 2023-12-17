#pragma once

class BlendState
{
public:
	BlendState();
	~BlendState();

	void SetState();

	void Alpha(bool Value);
	void Additive();
	void AlphaToConverage(bool Value);

	void Changed();

private:
	D3D11_BLEND_DESC Desc = {};
	ID3D11BlendState* State = nullptr;
};

