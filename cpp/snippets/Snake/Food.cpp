#include "Food.h"

void Food::creat(Map *map)
{
	COORD p;
	do
	{
		p = { random(0, (*map).getSize().X - 1), random(0, (*map).getSize().Y - 1) };
	} while ((*map).getCellOfBoard(p) != SI_FLOOR);
	position = p;
	(*map).setCellOfBoard(p, symbol);
}