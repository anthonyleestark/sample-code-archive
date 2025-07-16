#include "Scene.h"

void Scene::load(string sf)
{
	map = new Map;
	player = new Snake;
	food = new Food;
	getMapFile(sf, map, player);
	(*map).show(); 
	
	(*food).creat(map);
	(*food).show((*food).FRAME_POS);
	
	(*player).show();
}

void Scene::run()
{
	score.show();
	char newDir = (*player).getDirection();
	do
	{
		if (_kbhit())
		{
			short key = readKey();
			if (key == K_ESC)
				break;
			switch (key)
			{
			case K_LEFT:
				newDir = D_LEFT;
				break;
			case K_UP:
				newDir = D_UP;
				break;
			case K_RIGHT:
				newDir = D_RIGHT;
				break;
			case K_DOWN:
				newDir = D_DOWN;
				break;
			}
		}
		
		if (abs(newDir - player->getDirection()) == 2)
			newDir = (*player).getDirection();
		bool isEat = false;
		(*player).move(newDir, map, isEat);
		if (isEat)
		{
			
			score.increaseScore();
			score.show();
			(*food).hide((*food).FRAME_POS);
			delete food;
			(*(*player).getComponents()).front().show((*player).FRAME_POS);
			food = new Food;
			(*food).creat(map);
			(*food).show((*food).FRAME_POS);
		}

		Sleep(PING);
	} while ((*player).isAlive());
}

