#include "EnemyIdleState.h"
#include "Enemy.h"
#include "EnemyAI.h"
#include "SuspiciousState.h"
#include "PatrolState.h"



EnemyIdleState::EnemyIdleState()
{
}

EnemyIdleState::EnemyIdleState(Enemy* enemy, EnemyAI* ai)
{
	this->enemyAI = ai;
	enemyAI->countUpIgnore = 0;
	enemyAI->countUpAlert = 0;
	enemyAI->setVelo(enemy, D3DXVECTOR2(1, 1));
}

EnemyIdleState::~EnemyIdleState()
{
}

void EnemyIdleState::update(Enemy * enemy, Player * player, EnemyAI * ai, float frameTime)
{
	//enemy->setVisible(false);
	//if (enemyAI->countUpIdle >= IDLE_DURATION) {
	//	
	//}
	if (enemyAI->countUpIdle < IDLE_DURATION) {
		enemyAI->countUpIdle += frameTime;
	}

}

EnemyState * EnemyIdleState::handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime)
{
	if (enemyAI->playerInFov(enemy)) {
		return new SuspiciousState(enemyAI);
	}
	if (enemyAI->countUpIdle >= IDLE_DURATION) {
		randomDirection(enemy, frameTime);
		enemyAI->countUpIdle = 0;
		return new PatrolState(enemyAI);
	}

	return new EnemyIdleState(enemy, enemyAI);
}

void EnemyIdleState::randomDirection(Enemy * enemy, float frameTime)
{
	if (enemyAI->countUpIdle >= IDLE_DURATION) {
		D3DXVECTOR2 velocity = D3DXVECTOR2(MIN_MAX_RAND(-10, 10), MIN_MAX_RAND(-10, 10));
		D3DXVec2Normalize(&velocity, &velocity);
		enemyAI->setVelo(enemy, velocity * ENEMY_MOVE_SPEED);
		enemyAI->countUpIdle = 0;
	}

}
