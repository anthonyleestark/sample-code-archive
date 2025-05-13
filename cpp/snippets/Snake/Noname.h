#ifndef _NONAME_H
#define _NONAME_H

using namespace std;

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include "windows.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>

static HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
static HANDLE inpHandle = GetStdHandle(STD_INPUT_HANDLE);

const COORD DIF_POS[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

typedef vector<vector<char>> Vec2DChar;
 
enum KeyPress
{
	K_LEFT = -75,
	K_RIGHT = -77,
	K_UP = -72,
	K_DOWN = -80,
	K_ESC = 27,
	K_ENTER = 13
};

enum Symbol
{
	S_FILL = 219,
	S_SQUARE = 254,
	S_CIRCLE = 111,
	S_SPACE = 32,
	
	S_UULL = 201,
	S_UURR = 187,
	S_DDLL = 200,
	S_DDRR = 188,

	S_UL = 218,
	S_UR = 191,
	S_DL = 192,
	S_DR = 217,

	S_VVER = 205,
	S_HHOR = 186,
	
	S_VER = 196,
	S_HOR = 179,
};

enum Color
{
	C_BLACK = 0,
	C_BLUE = 1,
	C_GREEN = 2,
	C_AQUA = 3,
	C_RED = 4,
	C_PURPLE = 5,
	C_YELLOW = 6,
	C_WHITE = 7,
	C_GRAY = 8,
	C_LIGHT_BLUE = 9,
	C_LIGHT_GREEN = 10,
	C_LIGHT_AQUA = 11,
	C_LIGHT_RED = 12,
	C_LIGHT_PURPLE = 13,
	C_LIGHT_YELLOW = 14,
	C_LIGHT_WHITE = 15
};

enum Direction
{
	D_LEFT = 0,
	D_UP = 1,
	D_RIGHT = 2,
	D_DOWN = 3
};

enum SignInMapFile
{
	SI_SNAKE = 42,
	SI_WALL = 35,
	SI_FOOD = 111,
	SI_FLOOR = 32
};

enum SnakeConsts
{
	SS_HEAD = S_SQUARE,

	SC_HEAD = C_LIGHT_RED,
	SC_BODY = C_LIGHT_AQUA
};

enum MapConsts
{
	MS_WALL = S_FILL,
	MS_FLOOR = S_SPACE,

	MC_WALL = C_WHITE,
	MC_FLOOR = C_BLACK
};

enum ObjectConsts
{
	S_FOOD = S_CIRCLE,
	C_FOOD = C_LIGHT_GREEN,
	C_SCORE = C_LIGHT_YELLOW
};

static short random(short low, short high)
{
	return (low + rand() % (high - low + 1));
}

static char exchange(char &c)
{
	switch (c)
	{
	case SI_WALL:	
		c = MS_WALL;
		break;
	default:	
		c = MS_FLOOR;
	}	
	return c;
}

static void resizeConsole(int width, int height)
{
	_COORD coord;
	coord.X = width;
	coord.Y = height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = height - 1;
	Rect.Right = width - 1;

	SetConsoleScreenBufferSize(outHandle, coord);
	SetConsoleWindowInfo(outHandle, TRUE, &Rect);
}

static void gotoxy(COORD p)
{
	swap(p.X, p.Y);
	SetConsoleCursorPosition(outHandle, p);
}

static void setColor(int colorText, int colorBackground)
{
	SetConsoleTextAttribute(outHandle, colorText + 16 * colorBackground);
}

template <class T>
static void print(COORD p, T s, char color)
{
	setColor(color, 0);
	gotoxy(p);
	cout << s;
}

static short readKey()
{
	fflush(stdin);
	short c = _getch();
	if (c == 224)
	{
		c = _getch();
		return -c;
	}
	else
		return c;
}

static char getSymbolByDirection(char oldDir, char newDir)
{
	if (newDir == oldDir)
	{
		if (oldDir % 2)
			return S_HHOR;
		else
			return S_VVER;
	}
	if ((oldDir == D_UP && newDir == D_RIGHT) || (oldDir == D_LEFT && newDir == D_DOWN))
		return S_UULL;
	if ((oldDir == D_UP && newDir == D_LEFT) || (oldDir == D_RIGHT && newDir == D_DOWN))
		return S_UURR;
	if ((oldDir == D_DOWN && newDir == D_RIGHT) || (oldDir == D_LEFT && newDir == D_UP))
		return S_DDLL;
	if ((oldDir == D_DOWN && newDir == D_LEFT) || (oldDir == D_RIGHT && newDir == D_UP))
		return S_DDRR;
}

#endif // !_NONAME_H