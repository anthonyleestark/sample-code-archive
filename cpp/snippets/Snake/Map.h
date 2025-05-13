#ifndef _MAP_H
#define _MAP_H

#include "Noname.h"
#include "Point.h"
#include "Snake.h"

class Map
{
private:
	COORD size;

	Vec2DChar *board;

public:
	const COORD FRAME_POS = { 3, 9 };
	
	Map()
	{
		board = NULL;
	}

	~Map()
	{
		delete board;
		board = NULL;
	}

	COORD getSize();
	
	void setSize(COORD);
	
	void setBoard(Vec2DChar *);
	
	void setCellOfBoard(COORD, char);

	char getCellOfBoard(COORD);

	void show();
};

#endif // !_MAP_H
