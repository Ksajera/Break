#include "AlertState.h"
#include "Enemy.h"
#include "PatrolState.h"


AlertState::AlertState()
{
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

EnemyState* AlertState::handleEnemy(Enemy * enemy, EnemyAI * ai)
{
	if (!(ai->playerInFov(enemy))) {
		return new PatrolState();
	}
	return new AlertState();
}

void AlertState::chasePlayer(Enemy* enemy, Player* player) //for testing, just stop moving and look at player
{
	//enemy velo stop,
	//get vector to player and the angle from there,
	//rotate enemy to look at player
	enemy->setVelocity(D3DXVECTOR2(0, 0));
}
