#include "Enemy.h"



Enemy::Enemy()
{
	direction = DIRECTION::DOWN;
	moveFOV();
}


Enemy::~Enemy()
{
}

void Enemy::update(float frameTime) 
{
	physicsComponent.update(this, frameTime);
	//setPlayerPos(Player *player); // set VecEnemyToPlayer variable
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
	//prob dont need this func 
	//or at least change it to be called in another class to set direction in enemy ai 
}

void Enemy::moveFOV() 
{
	startFovAngle = direction - ENEMY_FOV_ANGLE_START; 
	endFovAngle = direction + ENEMY_FOV_ANGLE_START;
}

float Enemy::getEnemyToPlayerAngle() 
{
	float angle = 0;
	angle = atan2(VecEnemyToPlayer.y, VecEnemyToPlayer.x) * 180 / PI;
	return angle; 
}

bool Enemy::isPlayerInFov()
{
	/*
	if player within min angle and max angle
		return true
	else
		return false
	*/
	if (getEnemyToPlayerAngle() > startFovAngle && getEnemyToPlayerAngle() < endFovAngle)
		return true;
	else
		return false;
}

void Enemy::playerInFov()
{
	if (isPlayerInFov()) {
		//do the count down and stuff i guess
		//change sprite image color to test?
	}
}

void Enemy::setPlayerPos(Player *player) //call in update()
{
	VecEnemyToPlayer = player->getPosition() - getPosition(); 
}
