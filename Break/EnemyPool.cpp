#include "EnemyPool.h"



EnemyPool::EnemyPool()
{
}


EnemyPool::~EnemyPool()
{
}

void EnemyPool::create(D3DXVECTOR2 position, D3DXVECTOR2 velocity)
{
	for (auto it = enemyVector.begin(); it < enemyVector.end(); it++) {
		if (!(it->getActive())) {
			it->setActive(true);
			it->setVisible(true);
			it->setVelocity(velocity);
			it->setX(position.x);
			it->setY(position.y);
			return;
		}
	}
}

void EnemyPool::initialize(Enemy *enemy, int size)
{
	for (int i = 0; i < size; i++) {
		//enemy->setX(GAME_WIDTH / 2);
		//enemy->setY(GAME_HEIGHT / 2);
		enemy->setX(i*TILE_SIZE);
		enemy->setY(i*TILE_SIZE);
		enemyVector.push_back(*enemy);

		enemy->setDirection(RIGHT);
		enemy->moveFOV();
		enemy->setRadians(enemy->getDirection() * PI / 180); //convert degree(direction) to rad
		enemy->setVelo(D3DXVECTOR2(1, 1));
	}

}

void EnemyPool::update(float frameTime, Player *player)
{
	for (auto it = enemyVector.begin(); it < enemyVector.end(); it++) {
		it->update(frameTime, player);
	}

}

void EnemyPool::draw()
{
	for (auto it = enemyVector.begin(); it < enemyVector.end(); it++) {
		if (it->getActive())
			it->draw();
	}
}
