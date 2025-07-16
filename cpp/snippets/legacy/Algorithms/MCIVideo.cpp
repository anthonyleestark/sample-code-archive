#include "afxwin.h"
#include "windows.h"
#include "vfw.h"
#include "mciapi.h"
#include "mmsystem.h"
#pragma comment (lib, "winmm")
#pragma comment (lib, "vfw32")

void mcivideo_main()
{
	LPCWSTR filename = L"D:\\video.avi";
	HWND hConsoleWnd = GetConsoleWindow();
	HINSTANCE hInstance = (HINSTANCE) GetWindowLong(hConsoleWnd, GWLP_HINSTANCE);
	HWND hMediaWnd = MCIWndCreate(hConsoleWnd, hInstance, WS_VISIBLE | MCIWNDF_SHOWPOS | MCIWNDF_NOTIFYMODE, filename);
	RECT rect;
	GetClientRect(hConsoleWnd, &rect);
	SetWindowPos(hMediaWnd, HWND_NOTOPMOST, rect.left, rect.top, (rect.right - rect.left), (rect.bottom - rect.top), SWP_NOMOVE | SWP_NOREDRAW | SWP_NOACTIVATE | SWP_NOZORDER);
	while (TRUE)
	{
		MCIWndPlay(hMediaWnd);
		SuspendThread(GetCurrentThread());
	}
}