#include "windows.h"

void Circle(HDC hDC, POINT center, int radius)
{
	int left = center.x - radius;
	int top = center.y - radius;
	int right = center.x + radius;
	int bottom = center.y + radius;
	Ellipse(hDC, left, top, right, bottom);
}

void main()
{
	// Khởi tạo các thành phần đồ họa
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HBRUSH hRedBr1 = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hRedBr2 = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hWhiteBr1 = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hWhiteBr2 = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hBlueBr = CreateSolidBrush(RGB(0, 0, 255));

	// Lấy tâm màn hình console
	RECT rect;
	GetClientRect(hWnd, &rect);
	POINT center = { (rect.right - rect.left) / 2, (rect.bottom - rect.top) / 2 };

	SelectObject(hDC, hRedBr1); // Vòng thứ nhất
	Circle(hDC, center, 200);
	DeleteObject(hRedBr1);
	// Sleep(1000);

	SelectObject(hDC, hWhiteBr1); // Vòng thứ hai
	Circle(hDC, center, 167);
	DeleteObject(hWhiteBr1);
	// Sleep(1000);

	SelectObject(hDC, hRedBr2); // Vòng thứ ba
	Circle(hDC, center, 133);
	DeleteObject(hRedBr2);
	// Sleep(1000);

	SelectObject(hDC, hBlueBr); // Vòng trong
	Circle(hDC, center, 100);
	DeleteObject(hBlueBr);
	// Sleep(1000);

	SelectObject(hDC, hWhiteBr2); // Ngôi sao
	POINT point[11] = { 480, 140, 503, 208, 575, 208, 518, 252, 538, 320, 480, 280, 421, 320, 442, 252, 384, 208, 458, 208, 480, 140 };
	Polygon(hDC, point, 11);
	DeleteObject(hWhiteBr2);

	// Giải phóng DC
	ReleaseDC(hWnd, hDC);
}