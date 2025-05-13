#include "Noname.h"
#include "Map.h"
#include "Snake.h"
#include "File.h"
#include "Scene.h"

int main()
{
	resizeConsole(80, 25);
	system("color 07");
	// tile
	print({ 1, 30 }, "HUNTING SNAKE", C_LIGHT_AQUA);

	srand((unsigned int)time(NULL));
	Scene *scene = new Scene;
	
	(*scene).load("map2");
	(*scene).run();

	delete scene;
	scene = NULL;
	
	return 0;
}