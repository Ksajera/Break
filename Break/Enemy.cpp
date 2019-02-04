#include "Enemy.h"



Enemy::Enemy()
{
	direction = DIRECTION::DOWN;
}


Enemy::~Enemy()
{
}

void Enemy::update(float frameTime) 
{
	physicsComponent.update(this, frameTime);
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

void Enemy::draw()
{
	Image::draw();

}

bool Enemy::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	physicsComponent = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);
}

void Enemy::checkDirection() 
{
	//float rotation = 
}

void Enemy::moveFOV() 
{
	float x, y;
	if (direction % 2 == 0) {
		x = (getX() - getWidth() / 2) * (direction / 2);
		y = (getY() - getHeight() / 2) * (direction / 2);
	}
	else {
		x = (getX() - getWidth() / 2) * direction;
		y = (getY() - getHeight() / 2) * direction;
	}

	//enemyFOV->setPos(x, y);
}
