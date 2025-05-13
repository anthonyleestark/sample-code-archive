#ifndef _SNAKE_H
#define _SNAKE_H

#include "Noname.h"
#include "Map.h"
#include "Point.h"

class Map; // forward declaration

class Snake
{
private:
	
	list<Point> *components;
	
	char direction;
	
	bool alive;

	short length;

	
public:
	const COORD FRAME_POS = { 3, 9 };

	Snake()
	{
		direction = D_RIGHT;
		alive = true;
		components = NULL;
		length = 3;
	}

	~Snake()
	{
		delete components;
		components = NULL;
	}

	char getDirection();

	void setComponents(list<Point>*);
	
	list<Point> *getComponents();

	void show();

	void move(char, Map *, bool &);

	short getLength();

	bool isAlive();
};

#endif // !_SNAKE_H