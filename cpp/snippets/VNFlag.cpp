#include "windows.h"

void vnflag_main()
{
	// Khởi tạo các thành phần đồ họa
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hYellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	
	// Vẽ lá cờ màu đỏ
	SelectObject(hDC, hRedBrush);
	RECT clRect;
	GetClientRect(hWnd, &clRect);
	RECT rect = { clRect.left + 150, clRect.top + 50, clRect.right - 150, clRect.bottom - 50 };
	Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
	FillRect(hDC, &rect, hRedBrush);
	DeleteObject(hRedBrush);

	//Vẽ ngôi sao màu vàng
	SelectObject(hDC, hYellowBrush);
	SetBkColor(hDC, RGB(255, 255, 0));
	POINT point[11] = { 480, 140, 503, 208, 575, 208, 518, 252, 538, 320, 480, 280, 421, 320, 442, 252, 384, 208, 458, 208, 480, 140 };
	Polygon(hDC, point, 11);
	DeleteObject(hYellowBrush);

	// Giải phóng DC
	ReleaseDC(hWnd, hDC);
}