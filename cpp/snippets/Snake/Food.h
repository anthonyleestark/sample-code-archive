#ifndef _FOOD_H
#define _FOOD_H

#include "Noname.h"
#include "Point.h"
#include "Map.h"

class Food:public Point
{
private:
	
public:
	const COORD FRAME_POS = { 3, 9 };
	
	const char COLOR = C_FOOD;
	
	const char SYMBOL = S_FOOD;

	Food()
	{
		color = COLOR;
		symbol = SYMBOL;
	}

	void creat(Map *);
};

#endif // !_FOOD_H