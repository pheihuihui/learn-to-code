#include <sdkddkver.h>
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#include <Windows.h>
#include <d3d12.h>
#include <dxgi.h>

DWORD WINAPI RenderThreadMain(LPVOID lpThreadParameter) {

	HWND hWnd = static_cast<HWND>(lpThreadParameter);

#if defined(_DEBUG)
	//debug layer
	ID3D12Debug *pD3D12Debug;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&pD3D12Debug)))) {
		pD3D12Debug->EnableDebugLayer();
	}
	pD3D12Debug->Release();
#endif


	//create device
	IDXGIFactory *pDXGIFactory;
	CreateDXGIFactory(IID_PPV_ARGS(&pDXGIFactory));
	ID3D12Device *pD3D12Device = NULL;
	IDXGIAdapter *pDXGIAdapter;
	for (UINT i = 0U; SUCCEEDED(pDXGIFactory->EnumAdapters(i, &pDXGIAdapter)); ++i) {
		if (SUCCEEDED(D3D12CreateDevice(pDXGIAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&pD3D12Device)))) {
			pDXGIAdapter->Release();
			break;
		}
		pDXGIAdapter->Release();
	}

	//create command queue
	ID3D12CommandQueue *pDirectCommandQueue;
	D3D12_COMMAND_QUEUE_DESC cqdc;
	cqdc.Type = D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT;
	cqdc.Priority = D3D12_COMMAND_QUEUE_PRIORITY::D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
	cqdc.Flags = D3D12_COMMAND_QUEUE_FLAGS::D3D12_COMMAND_QUEUE_FLAG_NONE;
	cqdc.NodeMask = 0X1;
	pD3D12Device->CreateCommandQueue(&cqdc, IID_PPV_ARGS(&pDirectCommandQueue));


	//create swap chain
	IDXGISwapChain *pDXGISwapChain;
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
	pDXGIFactory->Release();


	ID3D12DescriptorHeap *pRTVHeap;
	D3D12_DESCRIPTOR_HEAP_DESC RTVHeapDesc = {
		D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
		1,
		D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		0X1
	};
	pD3D12Device->CreateDescriptorHeap(&RTVHeapDesc, IID_PPV_ARGS(&pRTVHeap));
	ID3D12Resource *pFrameBuffer;
	pDXGISwapChain->GetBuffer(0, IID_PPV_ARGS(&pFrameBuffer));
	pD3D12Device->CreateRenderTargetView(pFrameBuffer, NULL, pRTVHeap->GetCPUDescriptorHandleForHeapStart());


	//ID3D12CommandAllocator *pDirectCommandAllocator;
	//pD3D12Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&pDirectCommandAllocator));
	//ID3D12GraphicsCommandList *pDirectCommandList;
	//pD3D12Device->CreateCommandList(0X1, D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, pDirectCommandAllocator, NULL, IID_PPV_ARGS(&pDirectCommandList));



	ID3D12RootSignature *pGRS;
	HANDLE hGRSFile = CreateFileW(L"GRS.cso", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	LARGE_INTEGER szGRSFile;
	GetFileSizeEx(hGRSFile, &szGRSFile);
	HANDLE hGRSSection = CreateFileMappingW(hGRSFile, NULL, PAGE_READONLY, 0, szGRSFile.LowPart, NULL);
	void *pGRSFile = MapViewOfFile(hGRSSection, FILE_MAP_READ, 0, 0, szGRSFile.LowPart);
	pD3D12Device->CreateRootSignature(0X1, pGRSFile, szGRSFile.LowPart, IID_PPV_ARGS(&pGRS));
	UnmapViewOfFile(pGRSFile);
	CloseHandle(hGRSSection);
	CloseHandle(hGRSFile);

	ID3D12PipelineState *pGraphicPipelineState;
	HANDLE hVSFile = CreateFileW(L"VS.cso", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	LARGE_INTEGER szVSFile;
	GetFileSizeEx(hVSFile, &szVSFile);
	HANDLE hVSSection = CreateFileMappingW(hVSFile, NULL, PAGE_READONLY, 0, szVSFile.LowPart, NULL);
	void *pVSFile = MapViewOfFile(hVSSection, FILE_MAP_READ, 0, 0, szVSFile.LowPart);

	HANDLE hPSFile = CreateFileW(L"PS.cso", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	LARGE_INTEGER szPSFile;
	GetFileSizeEx(hPSFile, &szPSFile);
	HANDLE hPSSection = CreateFileMappingW(hPSFile, NULL, PAGE_READONLY, 0, szPSFile.LowPart, NULL);
	void *pPSFile = MapViewOfFile(hPSSection, FILE_MAP_READ, 0, 0, szPSFile.LowPart);

	D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc;
	psoDesc.pRootSignature = pGRS;

	psoDesc.InputLayout.NumElements = 0;
	psoDesc.InputLayout.pInputElementDescs = NULL;

	psoDesc.IBStripCutValue = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE::D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
	psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE::D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

	psoDesc.VS.pShaderBytecode = pVSFile;
	psoDesc.VS.BytecodeLength = szVSFile.LowPart;
	psoDesc.PS.pShaderBytecode = pPSFile;
	psoDesc.PS.BytecodeLength = szPSFile.LowPart;

	psoDesc.HS.pShaderBytecode = NULL;
	psoDesc.DS.pShaderBytecode = NULL;
	psoDesc.GS.pShaderBytecode = NULL;
	psoDesc.HS.BytecodeLength = 0;
	psoDesc.DS.BytecodeLength = 0;
	psoDesc.GS.BytecodeLength = 0;

	psoDesc.StreamOutput = {  };

	psoDesc.RasterizerState.FillMode = D3D12_FILL_MODE::D3D12_FILL_MODE_SOLID;
	psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
	psoDesc.RasterizerState.FrontCounterClockwise = FALSE;
	psoDesc.RasterizerState.DepthBias = 0;
	psoDesc.RasterizerState.DepthBiasClamp = 0.0f;
	psoDesc.RasterizerState.SlopeScaledDepthBias = 0.0f;
	psoDesc.RasterizerState.DepthClipEnable = FALSE;
	psoDesc.RasterizerState.MultisampleEnable = FALSE;
	psoDesc.RasterizerState.AntialiasedLineEnable = FALSE;
	psoDesc.RasterizerState.ForcedSampleCount = 0U;
	psoDesc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE::D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	psoDesc.NumRenderTargets = 1;
	psoDesc.RTVFormats[0] = DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;
	psoDesc.RTVFormats[1] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.RTVFormats[2] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.RTVFormats[3] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.RTVFormats[4] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.RTVFormats[5] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.RTVFormats[6] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.RTVFormats[7] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	psoDesc.DSVFormat = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;

	psoDesc.SampleDesc.Count = 1;
	psoDesc.SampleDesc.Quality = 0;

	psoDesc.SampleMask = 0XFFFFFFFF;

	psoDesc.DepthStencilState = {};
	psoDesc.DepthStencilState.DepthEnable = FALSE;
	psoDesc.DepthStencilState.StencilEnable = FALSE;

	psoDesc.BlendState = D3D12_BLEND_DESC{};
	psoDesc.BlendState.AlphaToCoverageEnable = FALSE;
	psoDesc.BlendState.IndependentBlendEnable = FALSE;
	psoDesc.BlendState.RenderTarget[0].BlendEnable = FALSE;
	psoDesc.BlendState.RenderTarget[0].LogicOpEnable = FALSE;
	psoDesc.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE::D3D12_COLOR_WRITE_ENABLE_ALL;

	psoDesc.NodeMask = 0X1;

	psoDesc.CachedPSO.pCachedBlob = NULL;
	psoDesc.CachedPSO.CachedBlobSizeInBytes = 0;

	psoDesc.Flags = D3D12_PIPELINE_STATE_FLAGS::D3D12_PIPELINE_STATE_FLAG_NONE;

	pD3D12Device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&pGraphicPipelineState));

	UnmapViewOfFile(pVSFile);
	CloseHandle(hVSSection);
	CloseHandle(hVSFile);

	UnmapViewOfFile(pPSFile);
	CloseHandle(hPSSection);
	CloseHandle(hPSFile);

	ID3D12CommandAllocator *pDirectCommandAllocator;
	pD3D12Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&pDirectCommandAllocator));

	ID3D12GraphicsCommandList *pDirectCommandList;
	pD3D12Device->CreateCommandList(0X1, D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, pDirectCommandAllocator, NULL, IID_PPV_ARGS(&pDirectCommandList));

	pDirectCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	D3D12_VIEWPORT vp = {
		4.0f,
		2.0f,
		500.0f,
		700.0f,
		3.0f,
		1.0f
	};
	pDirectCommandList->RSSetViewports(1, &vp);
	D3D12_RECT sr = { 1, 20, 1200, 340 };
	pDirectCommandList->RSSetScissorRects(1, &sr);
	pDirectCommandList->OMSetRenderTargets(1, &pRTVHeap->GetCPUDescriptorHandleForHeapStart(), FALSE, NULL);
	pDirectCommandList->SetGraphicsRootSignature(pGRS);
	pDirectCommandList->SetPipelineState(pGraphicPipelineState);

	D3D12_RESOURCE_BARRIER CommonToRenderTarget = {
		D3D12_RESOURCE_BARRIER_TYPE::D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,
		D3D12_RESOURCE_BARRIER_FLAGS::D3D12_RESOURCE_BARRIER_FLAG_NONE,
		pFrameBuffer,
		0,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_COMMON,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET
	};
	pDirectCommandList->ResourceBarrier(1, &CommonToRenderTarget);
	pDirectCommandList->DrawInstanced(3, 1, 0, 0);
	//float rgbacolor[4] = { 0.9f, 0.5f, 0.1f, 0.5f };
	//pDirectCommandList->ClearRenderTargetView(pRTVHeap->GetCPUDescriptorHandleForHeapStart(), rgbacolor, 0, NULL);

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
	pDirectCommandQueue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList**>(&pDirectCommandList));


	ID3D12Fence *pTestFence;
	pD3D12Device->CreateFence(5U, D3D12_FENCE_FLAGS::D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&pTestFence));

	pDirectCommandQueue->Wait(pTestFence, 7U);
	pDirectCommandQueue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList**>(&pDirectCommandList));

	pDXGISwapChain->Present(0, 0);

	MessageBoxW(hWnd, L"Continue", L"Fence Test", MB_OK);
	pTestFence->Signal(7U);

	return 0U;
}