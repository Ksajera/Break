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
	movementUpdate(enemy);
	enemy->setVelocity(velo);

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

void EnemyAI::playerInFov(Enemy* enemy)
{
	if (D3DXVec2Length(&VecEnemyToPlayer) <= TILE_SIZE * 5) { //if player is within 5 tiles infront
		if (isPlayerInFov()) {
			//do the count down and stuff i guess
			//change sprite image color to test?
			enemy->setActive(false);
			enemy->setVisible(false);
		}
		else {
			enemy->setActive(true);
		}	enemy->setVisible(true);
	}
}

void EnemyAI::setVecEnemyToPlayer(Enemy* enemy, Player *player) //call in update()
{
	VecEnemyToPlayer = player->getPosition() - enemy->getPosition();
}

void EnemyAI::movementUpdate(Enemy* enemy)
{
	// collide game width/height and bounce around
	if (enemy->getX() + enemy->getWidth() > GAME_WIDTH) { // top right
		enemy->setX(GAME_WIDTH - enemy->getWidth());
		//direction = DIRECTION(rand() % 4);
		setDirection(enemy, DOWN);
		setVelo(enemy, D3DXVECTOR2(1, 100));
	}

	if (enemy->getY() + enemy->getHeight() > GAME_HEIGHT) { //bottom right
		enemy->setY(GAME_HEIGHT - enemy->getHeight());
		//direction = DIRECTION(rand() % 4);
		setDirection(enemy, LEFT);
		setVelo(enemy, D3DXVECTOR2(-100, 1));
	}

	if ((enemy->getX() + TILE_SIZE) < 0) { // bottom left
		enemy->setX(0);
		//direction = DIRECTION(rand() % 4);
		setDirection(enemy, UP);
		setVelo(enemy, D3DXVECTOR2(1, -100));

	}

	if ((enemy->getY() + TILE_SIZE) < 0) { // top left
		enemy->setY(0);
		//direction = DIRECTION(rand() % 4);
		setDirection(enemy, RIGHT);
		setVelo(enemy, D3DXVECTOR2(100, 1));

	}

	enemy->setVelocity(velo);
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
	//enemy->setVelocity(vel);
	velo = vel;
}
