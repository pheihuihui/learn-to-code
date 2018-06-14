#include "stdafx.h"

DWORD WINAPI RenderThreadMain(LPVOID lpThreadParameter) {
	HWND hWnd = static_cast<HWND>(lpThreadParameter);
	return 0U;
}