#include <iostream>
using namespace std;

#define UP_DIR    1
#define DOWN_DIR  2
#define LEFT_DIR  3
#define RIGHT_DIR 4

int Direction(int &nWidthMatrix, int &nHeightMatrix, int nCurXPos, int nCurYPos, int nCurDir)
{
	if (nCurXPos == 1)
	{
		if (nCurDir == UP_DIR)
			return RIGHT_DIR;
		else if (nCurDir == LEFT_DIR)
		{
			nWidthMatrix++;
			nHeightMatrix++;
			return UP_DIR;
		}
	}
	else if (nCurYPos == 1)
	{
		if (nCurDir == DOWN_DIR)
		{
			nWidthMatrix++;
			nHeightMatrix++;
			return RIGHT_DIR;
		}
		else if (nCurDir == RIGHT_DIR)
			return UP_DIR;
	}
	else if (nCurXPos == nWidthMatrix + 1 && nCurYPos == nHeightMatrix + 1)
	{

		if (nCurDir == RIGHT_DIR)
			return DOWN_DIR;
		else if (nCurDir == UP_DIR)
			return LEFT_DIR;
	}
	else
		return nCurDir;
}

void Go(int nDirection, int &nCurXPos, int &nCurYPos)
{
	switch (nDirection)
	{
	case UP_DIR: nCurYPos++; break;
	case DOWN_DIR: nCurYPos--; break;
	case LEFT_DIR: nCurXPos--; break;
	case RIGHT_DIR: nCurXPos++; break;
	}
}

void Position(int nSecond, int &nXPos, int &nYPos)
{
	nXPos = 1; nYPos = 1;
	int nWM = 1, nHM = 1, xpos = 1, ypos = 2;
	int nCurrentDir = UP_DIR;
	if (nSecond >= 2)
	{
		for (int second = 2; second <= nSecond; second++)
		{
			// if (Direction(nWM, nHM, xpos, ypos) != nCurrentDir)
			nCurrentDir = Direction(nWM, nHM, xpos, ypos, nCurrentDir);
			Go(nCurrentDir, nXPos, nYPos);
			xpos = nXPos; ypos = nYPos;
		}
	}
}

int main()
{
	int nXPos, nYPos, nSecond;
	for (;;)
	{
		cin >> nSecond;
		if (nSecond == 0)
			return 0;
		else
		{
			Position(nSecond, nXPos, nYPos);
			cout << nYPos << " " << nXPos << endl;
		}
	}
	return 0;
}