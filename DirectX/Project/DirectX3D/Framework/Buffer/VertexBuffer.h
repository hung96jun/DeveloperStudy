#pragma once

class VertexBuffer
{
public:
	VertexBuffer(void* Data, UINT Stride, UINT Count);
	~VertexBuffer();

	void Set(D3D11_PRIMITIVE_TOPOLOGY Type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	void Set(UINT Slot, D3D11_PRIMITIVE_TOPOLOGY Type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	void Update(void* Data, UINT Count);

private:
	ID3D11Buffer* Buffer = nullptr;

	UINT Stride = 0;
	UINT Offset = 0;
};

