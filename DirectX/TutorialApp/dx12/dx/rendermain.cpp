#include "stdafx.h"

DWORD WINAPI RenderThreadMain(LPVOID lpThreadParameter) {

	HWND hWnd = static_cast<HWND>(lpThreadParameter);

#if defined(_DEBUG)
	//debug layer
	{
		ID3D12Debug *pD3D12Debug;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&pD3D12Debug)))) {
			pD3D12Debug->EnableDebugLayer();
		}
		pD3D12Debug->Release();
	}
#endif


	//create device
	IDXGIFactory *pDXGIFactory;
	CreateDXGIFactory(IID_PPV_ARGS(&pDXGIFactory));
	ID3D12Device *pD3D12Device = NULL;
	{
		IDXGIAdapter *pDXGIAdapter;
		for (UINT i = 0U; SUCCEEDED(pDXGIFactory->EnumAdapters(i, &pDXGIAdapter)); ++i) {
			if (SUCCEEDED(D3D12CreateDevice(pDXGIAdapter, D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&pD3D12Device)))) {
				pDXGIAdapter->Release();
				break;
			}
			pDXGIAdapter->Release();
		}
	}

	//create command queue
	ID3D12CommandQueue *pDirectCommandQueue;
	{
		D3D12_COMMAND_QUEUE_DESC cqdc;
		cqdc.Type = D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT;
		cqdc.Priority = D3D12_COMMAND_QUEUE_PRIORITY::D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
		cqdc.Flags = D3D12_COMMAND_QUEUE_FLAGS::D3D12_COMMAND_QUEUE_FLAG_NONE;
		cqdc.NodeMask = 0X1;
		pD3D12Device->CreateCommandQueue(&cqdc, IID_PPV_ARGS(&pDirectCommandQueue));
	}

	//create swap chain
	IDXGISwapChain *pDXGISwapChain;
	{
		DXGI_SWAP_CHAIN_DESC scdc;
		scdc.BufferDesc.Width = 0U;
		scdc.BufferDesc.Height = 0U;
		scdc.BufferDesc.RefreshRate.Numerator = 60U;
		scdc.BufferDesc.RefreshRate.Denominator = 1U;
		scdc.BufferDesc.Format = DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;
		scdc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER::DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		scdc.BufferDesc.Scaling = DXGI_MODE_SCALING::DXGI_MODE_SCALING_UNSPECIFIED;
		scdc.SampleDesc.Count = 1U;
		scdc.SampleDesc.Quality = 0U;
		scdc.BufferUsage = DXGI_USAGE_SHADER_INPUT;
		scdc.BufferCount = 2;
		scdc.OutputWindow = hWnd;
		scdc.Windowed = TRUE;
		scdc.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_SEQUENTIAL;
		scdc.Flags = 0U;
		pDXGIFactory->CreateSwapChain(pDirectCommandQueue, &scdc, &pDXGISwapChain);
	}
	pDXGIFactory->Release();

	pDXGISwapChain->Present(0, 0);

	return 0U;
}