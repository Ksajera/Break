#include "Tile.h"



Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::initialize(Graphics *g, const char *file)
{
	texture.initialize(g, file);
	imageComponent.initialize(g, TILE_SIZE, TILE_SIZE, 0, &texture);

}

void Tile::draw()
{
	imageComponent.draw();
}

void Tile::setPosition(int x, int y)
{
	imageComponent.setX(x * TILE_SIZE);
	imageComponent.setY(y * TILE_SIZE);
}
