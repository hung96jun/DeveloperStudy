#include "Framework.h"

VertexBuffer::VertexBuffer(void* Data, UINT Stride, UINT Count)
	: Stride(Stride)
{
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = Stride * Count;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = Data;

	DEVICE->CreateBuffer(&bufferDesc, &initData, &Buffer);
}

VertexBuffer::~VertexBuffer()
{
	Buffer->Release();
}

void VertexBuffer::Set(D3D11_PRIMITIVE_TOPOLOGY Type)
{
	DC->IASetVertexBuffers(0, 1, &Buffer, &Stride, &Offset);
	DC->IASetPrimitiveTopology(Type);
}

void VertexBuffer::Set(UINT Slot, D3D11_PRIMITIVE_TOPOLOGY Type)
{
	DC->IASetVertexBuffers(Slot, 1, &Buffer, &Stride, &Offset);
	DC->IASetPrimitiveTopology(Type);
}

void VertexBuffer::Update(void* Data, UINT Count)
{
	DC->UpdateSubresource(Buffer, 0, nullptr, Data, Stride, Count);
}
