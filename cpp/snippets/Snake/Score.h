#ifndef  _SCORE_H
#define _SCORE_H

#include "Noname.h"

class Score
{
private:
	long s;
		
public:
	const COORD FRAME_POS = { 3, 2 };

	const char COLOR = C_SCORE;

	Score()
	{
		s = 0;
		print(FRAME_POS, "Score ", C_SCORE);
		print({ FRAME_POS.X + 2, FRAME_POS.Y }, s, C_SCORE);
	}

	~Score()
	{
		print(FRAME_POS, "Score ", C_BLACK);
		print({ FRAME_POS.X + 2, FRAME_POS.Y }, s, C_BLACK);
	}

	void increaseScore();

	void show();

	void hide();

	short getScore();
};

#endif // ! _SCORE_H