#include "Score.h"

void Score::increaseScore()
{
	s++;
}

short Score::getScore()
{
	return s;
}

void Score::show()
{
	print({ FRAME_POS.X + 2, FRAME_POS.Y }, s, C_SCORE);
}