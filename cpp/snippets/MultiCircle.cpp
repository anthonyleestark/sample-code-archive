#include "windows.h"

void mCircle(HDC hDC, POINT center, int radius)
{
	int left = center.x - radius;
	int top = center.y - radius;
	int right = center.x + radius;
	int bottom = center.y + radius;
	Ellipse(hDC, left, top, right, bottom);
}

void multicircle_main()
{
	// Khởi tạo các thành phần đồ họa
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hDC, hPen);

	// Lấy tâm màn hình console
	RECT rect;
	GetClientRect(hWnd, &rect);
	POINT center = { (rect.right - rect.left) / 2, (rect.bottom - rect.top) / 2 };
	for (int i = 200; i >= 10; i -= 10)
		mCircle(hDC, center, i);

	// Giải phóng DC
	ReleaseDC(hWnd, hDC);
}