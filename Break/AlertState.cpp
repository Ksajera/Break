#include "AlertState.h"
#include "Enemy.h"
#include "PatrolState.h"

AlertState::AlertState()
{
}

AlertState::AlertState(EnemyAI* ai)
{
	this->enemyAI = ai;
}


AlertState::~AlertState()
{
}

void AlertState::enter(Enemy * enemy)
{
}

void AlertState::exit(Enemy * enemy)
{
}

void AlertState::update(Enemy * enemy, Player* player, EnemyAI* ai, float frameTime)
{
	chasePlayer(enemy, player);
}

EnemyState* AlertState::handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime)
{
	if (!(enemyAI->playerInFov(enemy))) {
		return new PatrolState(enemyAI);
	}
	return new AlertState(enemyAI);
}

void AlertState::chasePlayer(Enemy* enemy, Player* player) //for testing, just stop moving and look at player
{
	//enemy velo stop,
	//get vector to player and the angle from there,
	//rotate enemy to look at player
	D3DXVECTOR2 vecEtoP = enemyAI->getVecEnemyToPlayer();
	D3DXVec2Normalize(&vecEtoP, &vecEtoP);
	enemy->setVelocity(D3DXVECTOR2(vecEtoP.x, vecEtoP.y) * 100); 


	enemy->setRadians(enemyAI->getEnemyToPlayerAngle() + PI/2);
}
