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

void Enemy::setPosition(D3DXVECTOR2 position)
{
	setX(position.x);
	setY(position.y);
}

D3DXVECTOR2 Enemy::getPosition()
{
	return D3DXVECTOR2(getX(), getY());
}

