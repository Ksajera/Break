#include "EnemyFOV.h"



EnemyFOV::EnemyFOV()
{
}


EnemyFOV::~EnemyFOV()
{
}

void EnemyFOV::update(float frameTime) 
{
	//check col with player here?
}

bool EnemyFOV::initialize(Game *gamePtr, int width, int height, int ncols,TextureManager *textureM)
{
	return Entity::initialize(gamePtr, width, height, ncols, textureM);

}


void EnemyFOV::draw()
{
	Image::draw();
}

void EnemyFOV::setPosition(D3DXVECTOR2 position)
{
	setX(position.x);
	setY(position.y);
}

D3DXVECTOR2 EnemyFOV::getPosition()
{
	return D3DXVECTOR2(getX(), getY());
}

void EnemyFOV::setPos(float x, float y) 
{
	setX(x);
	setY(y);
}

