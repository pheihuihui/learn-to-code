#include <sdkddkver.h>
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#include <Windows.h>
#include <d3d12.h>
#include <dxgi.h>

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
			if (SUCCEEDED(D3D12CreateDevice(pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&pD3D12Device)))) {
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
		scdc.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
		scdc.Flags = 0U;
		pDXGIFactory->CreateSwapChain(pDirectCommandQueue, &scdc, &pDXGISwapChain);
	}
	pDXGIFactory->Release();


	ID3D12DescriptorHeap *pRTVHeap;
	{
		D3D12_DESCRIPTOR_HEAP_DESC RTVHeapDesc = {
			D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_RTV, 
			1,
			D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
			0X1
		};
		pD3D12Device->CreateDescriptorHeap(&RTVHeapDesc, IID_PPV_ARGS(&pRTVHeap));
	}
	ID3D12Resource *pFrameBuffer;
	pDXGISwapChain->GetBuffer(0, IID_PPV_ARGS(&pFrameBuffer));
	pD3D12Device->CreateRenderTargetView(pFrameBuffer, NULL, pRTVHeap->GetCPUDescriptorHandleForHeapStart());


	ID3D12CommandAllocator *pDirectCommandAllocator;
	pD3D12Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&pDirectCommandAllocator));
	ID3D12GraphicsCommandList *pDirectCommandList;
	pD3D12Device->CreateCommandList(0X1, D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, pDirectCommandAllocator, NULL, IID_PPV_ARGS(&pDirectCommandList));


	D3D12_RESOURCE_BARRIER CommonToRenderTarget = {
		D3D12_RESOURCE_BARRIER_TYPE::D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,
		D3D12_RESOURCE_BARRIER_FLAGS::D3D12_RESOURCE_BARRIER_FLAG_NONE,
		pFrameBuffer,
		0,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_COMMON,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET
	};
	pDirectCommandList->ResourceBarrier(1, &CommonToRenderTarget);
	float rgbacolor[4] = { 0.9f, 0.5f, 0.1f, 0.5f };
	pDirectCommandList->ClearRenderTargetView(pRTVHeap->GetCPUDescriptorHandleForHeapStart(), rgbacolor, 0, NULL);

	D3D12_RESOURCE_BARRIER RenderTargetToCommon = {
		D3D12_RESOURCE_BARRIER_TYPE::D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,
		D3D12_RESOURCE_BARRIER_FLAGS::D3D12_RESOURCE_BARRIER_FLAG_NONE,
		pFrameBuffer,
		0,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_COMMON
	};
	pDirectCommandList->ResourceBarrier(1, &RenderTargetToCommon);
	pDirectCommandList->Close();
	pDirectCommandQueue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList **>(&pDirectCommandList));



	pDXGISwapChain->Present(0, 0);

	return 0U;
}