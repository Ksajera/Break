#include "EnemyAI.h"
#include "Enemy.h"

EnemyAI::EnemyAI()
{
	//velo = D3DXVECTOR2(1, 0);
	countUpIgnore = 0;
	countUpAlert = 0;
	countUpPatrol = 0;
	countUpIdle = 0;
	randoDir = D3DXVECTOR2(0, 0);

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
	StayInScreen(enemy);
}

void EnemyAI::rotateEnemy(Enemy * enemy)
{
	enemy->setRadians(angleFaced);
}

void EnemyAI::moveFOV(Enemy* enemy)
{
	startFovAngle = angleFaced - ((ENEMY_FOV_ANGLE + 90) * PI / 180);
	endFovAngle = angleFaced + ((ENEMY_FOV_ANGLE + 90) * PI / 180);
}

float EnemyAI::getEnemyToPlayerAngle()
{
	float angle = 0;
	angle = atan2(VecEnemyToPlayer.y, VecEnemyToPlayer.x); //no need  * 180 / PI because image.angle is in rad
	return angle;
}

void EnemyAI::calcAngleFaced(D3DXVECTOR2 vec)
{
	angleFaced = atan2(vec.y, vec.x) + PI/2;
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
			//enemy->setVisible(false);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		//enemy->setVisible(true);
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

void EnemyAI::StayInScreen(Enemy* enemy)
{
	// collide game width/height
	if (enemy->getX() + enemy->getWidth() > GAME_WIDTH) { // top right
		enemy->setX(GAME_WIDTH - enemy->getWidth());
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, DOWN);
		//setVelo(enemy, D3DXVECTOR2(1, 100));
		calcAngleFaced(enemy->getVelocity());
	}

	if (enemy->getY() + enemy->getHeight() > GAME_HEIGHT) { //bottom right
		enemy->setY(GAME_HEIGHT - enemy->getHeight());
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, LEFT);
		//setVelo(enemy, D3DXVECTOR2(-100, 1));
		calcAngleFaced(enemy->getVelocity());
	}

	if ((enemy->getX() + TILE_SIZE) < 0) { // bottom left
		enemy->setX(0);
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, UP);
		//setVelo(enemy, D3DXVECTOR2(1, -100));
		calcAngleFaced(enemy->getVelocity());
	}

	if ((enemy->getY() + TILE_SIZE) < 0) { // top left
		enemy->setY(0);
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, RIGHT);
		//setVelo(enemy, D3DXVECTOR2(100, 1));
		calcAngleFaced(enemy->getVelocity());
	}

}