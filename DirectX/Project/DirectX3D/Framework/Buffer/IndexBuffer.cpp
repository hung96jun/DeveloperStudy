#include "Framework.h"

IndexBuffer::IndexBuffer(void* Data, UINT Count)
{
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(UINT);
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = Data;

	DEVICE->CreateBuffer(&bufferDesc, &initData, &Buffer);
}

IndexBuffer::~IndexBuffer()
{
	Buffer->Release();
}

void IndexBuffer::Set()
{
	DC->IASetIndexBuffer(Buffer, DXGI_FORMAT_R32_UINT, 0);
}

void IndexBuffer::Update(void* Data, UINT Count)
{
	DC->UpdateSubresource(Buffer, 0, nullptr, Data, sizeof(UINT), Count);
}
