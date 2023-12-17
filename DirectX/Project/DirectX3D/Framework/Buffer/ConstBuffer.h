#pragma once

class ConstBuffer
{
public:
	ConstBuffer(void* Data, UINT DataSize);
	~ConstBuffer();

	void SetVS(UINT Slot);
	void SetPS(UINT Slot);
	void SetCS(UINT Slot);

private:
	ID3D11Buffer* Buffer = nullptr;

	void* Data = nullptr;
	UINT DataSize = 0;

	D3D11_MAPPED_SUBRESOURCE SubResource;
};

