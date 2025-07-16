#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "windows.h"
using namespace std;

void bubble_main()
{
	srand((unsigned int)time(NULL));
	HWND hConsoleWnd = GetConsoleWindow();
	HDC hConsoleDC = GetDC(hConsoleWnd);
	HPEN hPen;
	RECT wrect; GetClientRect(hConsoleWnd, &wrect);
	POINT point;
	point.x = (wrect.right - wrect.left) / 2;
	point.y = (wrect.bottom - wrect.top) / 2;
	int line;
	for (;;)
	{
		int red = rand() % 255, green = rand() % 255, blue = rand() % 255;
		hPen = CreatePen(PS_SOLID, 5, RGB(red, green, blue));
		SelectObject(hConsoleDC, hPen);
		MoveToEx(hConsoleDC, point.x, point.y, NULL);
		point.x = rand() % 1366; point.y = rand() % 768;
		line = rand() % 50 + 10;
		ScreenToClient(hConsoleWnd, &point);
		// LineTo(hConsoleDC, point.x, point.y);
		Ellipse(hConsoleDC, point.x - line, point.y - line, point.x + line, point.y + line);
		Sleep(50);
	}
	DeleteDC(hConsoleDC);
	ReleaseDC(hConsoleWnd, hConsoleDC);
}
