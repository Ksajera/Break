#include "World.h"
#include <time.h> 
using namespace WorldNS;
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

void World::update(Player & player, float frameTime)
{

	//map doesnt render if this isnt here
	float playerX = player.getX();
	if (playerX < 0)                  // if butterfly off screen left
	{
		mapX -= player.getVelocity().x * frameTime;  // scroll map right
		player.setX(0);              // put butterfly at left edge
	}
	// if butterfly off screen right
	else if (playerX > GAME_WIDTH - player.getWidth())
	{
		mapX -= player.getVelocity().x * frameTime;  // scroll map left
		// put butterfly at right edge
		player.setX((float)(GAME_WIDTH - player.getWidth()));
	}

	//For bullet hell
	//if (mapX > 0)    // if map past left edge
	//{
	//	mapX = 0;   // stop at left edge of map
	//	player.setVelocity(D3DXVECTOR2(0, 0));  // stop butterfly
	//}
	//// if map past right edge
	//else if (mapX < (-MAP_WIDTH * TEXTURE_SIZE) + GAME_WIDTH)
	//{
	//	// stop at right edge of map
	//	mapX = (-MAP_WIDTH * TEXTURE_SIZE) + GAME_WIDTH;
	//	player.setVelocity(D3DXVECTOR2(0,0));  // stop butterfly
	//}
}

void World::draw()
{
	/*for (int x = 0; x < WORLD_WIDTH; x++) {
		for (int y = 0; y < WORLD_HEIGHT; y++) {
			tiles[x][y]->setPosition(x, y);
			tiles[x][y]->draw();

		}
	}*/

	for (int row = 0; row < MAP_HEIGHT; row++)       // for each row of map
	{
		tileImage.setY((float)(row*TEXTURE_SIZE)); // set tile Y
		for (int col = 0; col < MAP_WIDTH; col++)    // for each column of map
		{
			if (tileMap[row][col] >= 0)          // if tile present
			{
				tileImage.setCurrentFrame(tileMap[row][col]);    // set tile texture

				tileImage.setX((float)(col*TEXTURE_SIZE) + mapX);   // set tile X
				//tileImage.setY((float)(col*TEXTURE_SIZE) + mapY);   // set tile Y
				// if tile on screen
				if (tileImage.getX() > -TEXTURE_SIZE && tileImage.getX() < GAME_WIDTH)
					tileImage.draw();                // draw tile
				/*if (tileImage.getY() > -TEXTURE_SIZE && tileImage.getY() < GAME_HEIGHT)
					tileImage.draw();      */          // draw tile
			}
		}
	}
}

void World::initialize(Graphics *g, Image tile)
{
	//dirtTile.initialize(g, DIRT_IMAGE);
	//grassTile.initialize(g, GRASS_IMAGE);
	////floorTile.initialize(g, FLOOR_IMAGE);
	//generateWorld();
	tileImage = tile;
	mapX = 0;

}
