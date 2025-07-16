#include "Map.h"

COORD Map::getSize()
{
	return size;
}

void Map::setSize(COORD sz)
{
	size = sz;
}

void Map::setBoard(Vec2DChar *pBoard)
{
	board = pBoard;
}

void Map::setCellOfBoard(COORD position, char c)
{
	(*board)[position.X][position.Y] = c;
}

char Map::getCellOfBoard(COORD position)
{
	return (*board)[position.X][position.Y];
}

void Map::show()
{
	for (short i = 0; i < size.X; i++)
		for (short j = 0; j < size.Y; j++)
			switch ((*board)[i][j])
			{
			case (char)MS_WALL:
				print({ i + FRAME_POS.X, j + FRAME_POS.Y }, (char)MS_WALL, MC_WALL);
				break;
			case (char)MS_FLOOR:
				print({ i + FRAME_POS.X, j + FRAME_POS.Y }, (char)MS_FLOOR, MC_FLOOR);
				break;
			}
}