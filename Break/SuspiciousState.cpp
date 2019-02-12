#include "SuspiciousState.h"
#include "EnemyAI.h"
#include "PatrolState.h"
#include "AlertState.h"
#include "Enemy.h"

SuspiciousState::SuspiciousState()
{
}

SuspiciousState::SuspiciousState(EnemyAI* ai)
{
	this->enemyAI = ai;
}

SuspiciousState::~SuspiciousState()
{
}

void SuspiciousState::update(Enemy * enemy, Player * player, EnemyAI * ai, float frameTime)
{
	//enemy->setVisible(false);
	//player is NOT in FOV
	//if (!(enemyAI->playerInFov(enemy))) { 
	//	enemyAI->countUpIgnore = 0;
	//	enemyAI->countUpAlert = 0;
	//}
	if (!(enemyAI->playerInFov(enemy)) && enemyAI->countUpIgnore < TIME_TAKEN_TO_IGNORE) {
		enemyAI->countUpIgnore += frameTime;
	}

	//player is in FOV
	//if (enemyAI->playerInFov(enemy)) { 
	//	enemyAI->countUpIgnore = 0;
	//	enemyAI->countUpAlert = 0;
	//}
	if ((enemyAI->playerInFov(enemy)) && enemyAI->countUpAlert < TIME_TAKEN_TO_ALERT) {
		enemyAI->countUpAlert += frameTime;
	}
}

EnemyState * SuspiciousState::handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime)
{
	//player is NOT in FOV
	if (!(enemyAI->playerInFov(enemy)) && enemyAI->countUpIgnore >= TIME_TAKEN_TO_IGNORE) {
		enemyAI->countUpIgnore = 0;
		return new PatrolState(enemyAI);
	}

	//player is in FOV
	if ((enemyAI->playerInFov(enemy)) && enemyAI->countUpAlert >= TIME_TAKEN_TO_ALERT) {
		enemyAI->countUpIgnore = 0;
		return new AlertState(enemyAI);
	}
	                                                                            
	return new SuspiciousState(enemyAI);
}

/*if (!(enemyAI->playerInFov(enemy))) 
	countUP 3 secs?
  if (!(enemyAI->playerInFov(enemy)) and countdown >= TIME_TAKEN_TO_IGNORE) 
	change state to patrolstate()

  if (enemyAI->playerInFov(enemy)) 
    countUP 5 seconds?
  if (enemyAI->playerInFov(enemy) and countdown >= TIME_TAKEN_TO_ALERT)
    change state to alertstate()

*/