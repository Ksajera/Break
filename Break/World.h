#pragma once
#include "image.h"
#include "Tile.h"

class World
{
private:
	
	Tile* tiles[GAME_WIDTH][GAME_HEIGHT];
	void generateWorld();
	Tile dirtTile;
	Tile grassTile;
	Tile floorTile;

public:
	World();
	~World();
	void draw();
	void initialize(Graphics * g);

};

