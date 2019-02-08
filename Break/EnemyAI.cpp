#include "EnemyAI.h"
#include "Enemy.h"

EnemyAI::EnemyAI()
{
	//velo = D3DXVECTOR2(1, 0);
}


EnemyAI::~EnemyAI()
{
}

void EnemyAI::update(Enemy *enemy, Player *player, float frameTime)
{
	setVecEnemyToPlayer(enemy, player); // set VecEnemyToPlayer variable
	playerInFov(enemy);
	moveFOV(enemy);
	//movementUpdate(enemy);
	//enemy->setVelocity(velo);

}

void EnemyAI::moveFOV(Enemy* enemy)
{
	startFovAngle = enemy->getDirection() - ENEMY_FOV_ANGLE_START - 90; 
	endFovAngle = enemy->getDirection() + ENEMY_FOV_ANGLE_START - 90;
}

float EnemyAI::getEnemyToPlayerAngle()
{
	float angle = 0;
	angle = atan2(VecEnemyToPlayer.y, VecEnemyToPlayer.x) * 180 / PI; //no need  * 180 / PI because image.angle is in rad
	return angle;
}

bool EnemyAI::isPlayerInFov()
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

bool EnemyAI::playerInFov(Enemy* enemy)
{
	if (D3DXVec2Length(&VecEnemyToPlayer) <= TILE_SIZE * 5) { //if player is within 5 tiles infront
		if (isPlayerInFov()) {
			//do the count down and stuff i guess
			//enemy->setActive(false);
			//enemy->setVisible(false);
			return true;
		}
		else {
			//enemy->setActive(true);
			//enemy->setVisible(true);
			return false;
		}
	}
	else {
		//enemy->setActive(true);
		//enemy->setVisible(true);
		return false;
	}
}

void EnemyAI::setVecEnemyToPlayer(Enemy* enemy, Player *player) //call in update()
{
	VecEnemyToPlayer = player->getPosition() - enemy->getPosition();
}

int EnemyAI::getDirection(Enemy* enemy) {
	return enemy->getDirection();
}

void EnemyAI::setDirection(Enemy* enemy, int dir) {
	enemy->setDirection(dir);
}

D3DXVECTOR2 EnemyAI::getVelo(Enemy* enemy) {
	return enemy->getVelocity();
}

void EnemyAI::setVelo(Enemy* enemy, D3DXVECTOR2 vel) {
	enemy->setVelocity(vel);
	//velo = vel;
}
