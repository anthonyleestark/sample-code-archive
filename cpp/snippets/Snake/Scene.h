#ifndef _SCENE_H
#define _SCENE_H

#include "Map.h"
#include "Snake.h"
#include "File.h"
#include "Food.h"
#include "Score.h"

class Scene
{
private:
	Score score;

	Food *food;

	Snake *player;

	Map *map;

	const short PING = 100;
public:
	
	Scene()
	{
		player = NULL;
		food = NULL;
		map = NULL;
	}

	~Scene()
	{
		delete player;
		player = NULL;
		delete map;
		map = NULL;
		delete food;
		food = NULL;
	}

	void load(string);
	
	void run();
};


#endif // !_SCENE_H