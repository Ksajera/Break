#include "EnemyAI.h"
#include "Enemy.h"

EnemyAI::EnemyAI()
{
	//velo = D3DXVECTOR2(1, 0);
	countUpIgnore = 0;
	countUpAlert = 0;
	fovAngle = 0;
	startFovAngle = 0;
	endFovAngle = 0;
	angleFaced = PI;
	VecEnemyToPlayer = D3DXVECTOR2(0, 0);
}


EnemyAI::~EnemyAI()
{
}

void EnemyAI::update(Enemy *enemy, Player *player, float frameTime)
{
	setVecEnemyToPlayer(enemy, player); // set VecEnemyToPlayer variable
	//playerInFov(enemy);
	rotateEnemy(enemy);
	moveFOV(enemy);
}

void EnemyAI::rotateEnemy(Enemy * enemy)
{
	enemy->setRadians(angleFaced);
}

void EnemyAI::moveFOV(Enemy* enemy)
{
	startFovAngle = angleFaced - (ENEMY_FOV_ANGLE - 90) * PI / 180;
	endFovAngle = angleFaced + (ENEMY_FOV_ANGLE - 90) * PI / 180;
}

float EnemyAI::getEnemyToPlayerAngle()
{
	float angle = 0;
	angle = atan2(VecEnemyToPlayer.y, VecEnemyToPlayer.x); //no need  * 180 / PI because image.angle is in rad
	return angle;
}

float EnemyAI::calcAngleFaced(D3DXVECTOR2 vec)
{
	float angle = 0;
	angleFaced = atan2(vec.y, vec.x) + PI/2;
	//angle = 
	return angle;
}

void EnemyAI::setAngleFaced(float angle)
{
	angleFaced = angle;
}

bool EnemyAI::isPlayerInFov()
{
	if (getEnemyToPlayerAngle() > startFovAngle && getEnemyToPlayerAngle() < endFovAngle)
		return true;
	else
		return false;
}

bool EnemyAI::playerInFov(Enemy* enemy)
{
	if (D3DXVec2Length(&VecEnemyToPlayer) <= TILE_SIZE * ENEMY_FOV_RANGE) { //if player is within 5 tiles infront
		float pp = getEnemyToPlayerAngle();
		if (getEnemyToPlayerAngle() > startFovAngle && getEnemyToPlayerAngle() < endFovAngle) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

D3DXVECTOR2 EnemyAI::getVecEnemyToPlayer()
{
	return VecEnemyToPlayer;
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
