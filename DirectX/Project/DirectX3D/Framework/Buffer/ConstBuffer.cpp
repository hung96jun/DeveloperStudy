#include "Framework.h"

ConstBuffer::ConstBuffer(void* Data, UINT DataSize)
	: Data(Data), DataSize(DataSize)
{
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	bufferDesc.ByteWidth = DataSize;
	bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bufferDesc.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;

	DEVICE->CreateBuffer(&bufferDesc, nullptr, &Buffer);
}

ConstBuffer::~ConstBuffer()
{
	Buffer->Release();
}

void ConstBuffer::SetVS(UINT Slot)
{
	DC->Map(Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &SubResource);
	memcpy(SubResource.pData, Data, DataSize);
	DC->Unmap(Buffer, 0);

	DC->VSSetConstantBuffers(Slot, 1, &Buffer);
}

void ConstBuffer::SetPS(UINT Slot)
{
	DC->Map(Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &SubResource);
	memcpy(SubResource.pData, Data, DataSize);
	DC->Unmap(Buffer, 0);

	DC->PSSetConstantBuffers(Slot, 1, &Buffer);
}

void ConstBuffer::SetCS(UINT Slot)
{
	DC->Map(Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &SubResource);
	memcpy(SubResource.pData, Data, DataSize);
	DC->Unmap(Buffer, 0);

	DC->CSSetConstantBuffers(Slot, 1, &Buffer);
}
