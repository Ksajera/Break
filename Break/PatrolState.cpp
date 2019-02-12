#include "PatrolState.h"
#include "Enemy.h"
#include "AlertState.h"
#include "SuspiciousState.h"
#include "EnemyIdleState.h"

//default state for enemy

PatrolState::PatrolState()
{
}

PatrolState::PatrolState(EnemyAI* ai)
{
	this->enemyAI = ai;
	enemyAI->countUpIgnore = 0;
	enemyAI->countUpAlert = 0;
}

PatrolState::~PatrolState()
{
}

void PatrolState::enter(Enemy * enemy)
{
	
}

void PatrolState::exit(Enemy * enemy)
{
}

void PatrolState::update(Enemy * enemy, Player* player, EnemyAI* ai, float frameTime)
{
	//the basic path finding stuff
	//set points around the map etc.
	//movementUpdate(enemy, enemyAI);
	enemyAI->calcAngleFaced(enemy->getVelocity()); //setting teh angle herre too lazy to change
	if (enemyAI->countUpIdle < IDLE_DURATION){
		enemyAI->countUpPatrol += frameTime;
	}

}

EnemyState * PatrolState::handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime)
{
	if (enemyAI->playerInFov(enemy)) {
		//enemy->setVisible(false);
		return new SuspiciousState(enemyAI);
	}
	if (enemyAI->countUpPatrol >= PATROL_DURATION) {
		enemyAI->countUpPatrol = 0;
		return new EnemyIdleState(enemy, enemyAI);
	}

	return new PatrolState(enemyAI);
}

void PatrolState::movementUpdate(Enemy* enemy, EnemyAI* ai) // for 3 seconds, pause for 2 seconds, get a random direction, repeat
{
	// collide game width/height and bounce around
	if (enemy->getX() + enemy->getWidth() > GAME_WIDTH) { // top right
		enemy->setX(GAME_WIDTH - enemy->getWidth());
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, DOWN);
		enemyAI->setVelo(enemy, D3DXVECTOR2(1, 100));
		enemyAI->calcAngleFaced(enemy->getVelocity());
	}

	if (enemy->getY() + enemy->getHeight() > GAME_HEIGHT) { //bottom right
		enemy->setY(GAME_HEIGHT - enemy->getHeight());
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, LEFT);
		enemyAI->setVelo(enemy, D3DXVECTOR2(-100, 1));
		enemyAI->calcAngleFaced(enemy->getVelocity());
	}

	if ((enemy->getX() + TILE_SIZE) < 0) { // bottom left
		enemy->setX(0);
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, UP);
		enemyAI->setVelo(enemy, D3DXVECTOR2(1, -100));
		enemyAI->calcAngleFaced(enemy->getVelocity());
	}

	if ((enemy->getY() + TILE_SIZE) < 0) { // top left
		enemy->setY(0);
		//direction = DIRECTION(rand() % 4);
		//enemyAI->setDirection(enemy, RIGHT);
		enemyAI->setVelo(enemy, D3DXVECTOR2(100, 1));
		enemyAI->calcAngleFaced(enemy->getVelocity());
	}

}
