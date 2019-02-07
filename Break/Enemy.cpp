#include "Enemy.h"



Enemy::Enemy()
{
	direction = RIGHT;
	//moveFOV();
	spriteData.angle = direction * PI/180; //convert degree(direction) to rad
	velo = D3DXVECTOR2(1000, 1);
}

Enemy::~Enemy()
{
}

void Enemy::update(float frameTime, Player *player)
{
	physicsComponent.update(this, frameTime);
	enemyAI.update(this, player, frameTime);
	spriteData.angle = direction * PI / 180; //convert degree(direction) to rad

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


int Enemy::getDirection() {
	return direction;
}

void Enemy::setDirection(int dir) {
	direction = dir;
}

D3DXVECTOR2 Enemy::getVelo() {
	return velocity;
}

void Enemy::setVelo(D3DXVECTOR2 vel) {
	velocity = vel;
}

