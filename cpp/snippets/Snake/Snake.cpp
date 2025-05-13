#include "Snake.h"

void Snake::setComponents(list<Point> *pComp) 
{
	components = pComp;
}

list<Point>* Snake::getComponents()
{
	return components;
}

void Snake::move(char newDir, Map *map, bool &eat)
{
	// calculation new head position
	COORD newPos = (*components).front().getPosition();
	
	newPos.X += DIF_POS[newDir].X;
	newPos.Y += DIF_POS[newDir].Y;

	// over range of board -> reverse
	if (newPos.X < 0)
		newPos.X = (*map).getSize().X - 1;
	if (newPos.X >= (*map).getSize().X)
		newPos.X = 0;

	if (newPos.Y < 0)
		newPos.Y = (*map).getSize().Y - 1;
	if (newPos.Y >= (*map).getSize().Y)
		newPos.Y = 0;

	// lost
	if (	(*map).getCellOfBoard(newPos) == (char)MS_WALL
		||	(*map).getCellOfBoard(newPos) == (char)SI_SNAKE)
		alive = false;
	else
	{
		// move tail
		if ((*map).getCellOfBoard(newPos) != SI_FOOD)
		{
			// remove old tail
			(*map).setCellOfBoard((*components).back().getPosition(), SI_FLOOR);
			(*components).back().hide(FRAME_POS);
			(*components).pop_back();
			
			// change new tail symbol
			switch ((*components).back().getSymbol())
			{
			case (char)S_VVER:
				(*components).back().setSymbol(S_VER);
				break;
			case (char)S_HHOR:
				(*components).back().setSymbol(S_HOR);
				break;
			case (char)S_UULL:
				(*components).back().setSymbol(S_UL);
				break;
			case (char)S_UURR:
				(*components).back().setSymbol(S_UR);
				break;
			case (char)S_DDLL:
				(*components).back().setSymbol(S_DL);
				break;
			case (char)S_DDRR:
				(*components).back().setSymbol(S_DR);
				break;
			}
			(*components).back().show(FRAME_POS);
		}
		// eat: length increase, dont move tail
		else
			eat = true;

		// change head symbol before move
		(*components).front().setSymbol(getSymbolByDirection(direction, newDir));
		(*components).front().setColor(SC_BODY);
		(*components).front().show(FRAME_POS);
		
		// move head
		Point p;
		p.setPosition(newPos);
		p.setSymbol(SS_HEAD);
		p.setColor(SC_HEAD);
		(*components).push_front(p);

		(*map).setCellOfBoard((*components).front().getPosition(), SI_SNAKE);
		(*components).front().show(FRAME_POS);
		
		// set new direction
		direction = newDir;
	}
}

void Snake::show()
{
	for (list<Point>::iterator iComponents = (*components).begin(); iComponents != (*components).end(); iComponents++)
		//(*iComponents).show();
		// have FRAME so can't use Point.show()
		print({ (*iComponents).getPosition().X + FRAME_POS.X, (*iComponents).getPosition().Y + FRAME_POS.Y}, (*iComponents).getSymbol(), (*iComponents).getColor());
}

char Snake::getDirection()
{
	return direction;
}

short Snake::getLength()
{
	return length;
}

bool Snake::isAlive()
{
	return alive;
}