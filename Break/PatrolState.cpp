#include "PatrolState.h"
#include "Enemy.h"
#include "AlertState.h"
#include "SuspiciousState.h"


//default state for enemy

PatrolState::PatrolState()
{
}

PatrolState::PatrolState(EnemyAI* ai)
{
	this->enemyAI = ai;
}

PatrolState::~PatrolState()
{
}

void PatrolState::enter(Enemy * enemy)
{
	enemy->setVelocity(D3DXVECTOR2(100, 0));
}

void PatrolState::exit(Enemy * enemy)
{
}

void PatrolState::update(Enemy * enemy, Player* player, EnemyAI* ai, float frameTime)
{
	//the basic path finding stuff
	//set points around the map etc.
	movementUpdate(enemy, enemyAI);
}

EnemyState * PatrolState::handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime)
{
	if (enemyAI->playerInFov(enemy)) {
		return new SuspiciousState(enemyAI);
	}

	return new PatrolState(enemyAI);
}

void PatrolState::movementUpdate(Enemy* enemy, EnemyAI* ai)
{
	// collide game width/height and bounce around
	if (enemy->getX() + enemy->getWidth() > GAME_WIDTH) { // top right
		enemy->setX(GAME_WIDTH - enemy->getWidth());
		//direction = DIRECTION(rand() % 4);
		enemyAI->setDirection(enemy, DOWN);
		enemyAI->setVelo(enemy, D3DXVECTOR2(1, 100));
	}

	if (enemy->getY() + enemy->getHeight() > GAME_HEIGHT) { //bottom right
		enemy->setY(GAME_HEIGHT - enemy->getHeight());
		//direction = DIRECTION(rand() % 4);
		enemyAI->setDirection(enemy, LEFT);
		enemyAI->setVelo(enemy, D3DXVECTOR2(-100, 1));
	}

	if ((enemy->getX() + TILE_SIZE) < 0) { // bottom left
		enemy->setX(0);
		//direction = DIRECTION(rand() % 4);
		enemyAI->setDirection(enemy, UP);
		enemyAI->setVelo(enemy, D3DXVECTOR2(1, -100));

	}

	if ((enemy->getY() + TILE_SIZE) < 0) { // top left
		enemy->setY(0);
		//direction = DIRECTION(rand() % 4);
		enemyAI->setDirection(enemy, RIGHT);
		enemyAI->setVelo(enemy, D3DXVECTOR2(100, 1));

	}

}

