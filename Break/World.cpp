#include "World.h"
#include <time.h> 

void World::generateWorld()
{
	srand(time(NULL));
	for (int x = 0; x < WORLD_WIDTH; x++) {
		for (int y = 0; y < WORLD_HEIGHT; y++) {
			
			//1 in 10 chance of dirt tile
			//if ((rand() % 10) == 0)
			//	tiles[x][y] = &dirtTile;
			//else
				tiles[x][y] = &floorTile;
		}
	}
}



World::World()
{
}


World::~World()
{
}

void World::draw()
{
	for (int x = 0; x < WORLD_WIDTH; x++) {
		for (int y = 0; y < WORLD_HEIGHT; y++) {
			tiles[x][y]->setPosition(x, y);
			tiles[x][y]->draw();

		}
	}
}

void World::initialize(Graphics *g)
{
	dirtTile.initialize(g, DIRT_IMAGE);
	grassTile.initialize(g, GRASS_IMAGE);
	floorTile.initialize(g, FLOOR_IMAGE);
	generateWorld();

}
