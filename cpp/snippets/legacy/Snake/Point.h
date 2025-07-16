#ifndef _POINT_H
#define _POINT_H

#include "Noname.h"

class Point
{
protected:
	COORD position;
	
	char color;

	char symbol;

public:
	Point()
	{
		color = C_WHITE;
	}

	void setPosition(COORD);

	COORD getPosition();

	void setSymbol(char);

	char getSymbol();

	void show(const COORD);

	void hide(const COORD);

	void setColor(char);

	char getColor();
};

#endif // !_POINT_H