#pragma once

class Device
{
public:
	Device();
	~Device();

	void Clear();
	void Present();

	ID3D11Device* GetDevice() { return DeviceAdapter; }
	ID3D11DeviceContext* GetDeviceContext() { return DeviceContext; }
	IDXGISwapChain* GetSwapChain() { return SwapChain; }

private:
	ID3D11Device* DeviceAdapter;
	ID3D11DeviceContext* DeviceContext;

	IDXGISwapChain* SwapChain;
	ID3D11RenderTargetView* RenderTargetView;
	ID3D11DepthStencilView* DepthStencilView;
};

