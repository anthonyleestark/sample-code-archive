#include "Point.h"

void Point::setPosition(COORD pp)
{
	position = pp;
}

COORD Point::getPosition()
{
	return position;
}

void Point::setSymbol(char c)
{
	symbol = c;
}

char Point::getSymbol()
{
	return symbol;
}

void Point::show(const COORD FRAME_POS)
{
	print({ position.X + FRAME_POS.X, position.Y + FRAME_POS.Y }, (char)symbol, color);
}

void Point::hide(const COORD FRAME_POS)
{
	print({position.X + FRAME_POS.X, position.Y + FRAME_POS.Y}, (char)S_SPACE, 0);
}

void Point::setColor(char c)
{
	color = c;
}

char Point::getColor()
{
	return color;
}