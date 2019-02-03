#include "EnemyFOVpool.h"



EnemyFOVpool::EnemyFOVpool()
{
}


EnemyFOVpool::~EnemyFOVpool()
{
}

void EnemyFOVpool::create(D3DXVECTOR2 position, D3DXVECTOR2 velocity)
{
	for (auto it = enemyFOVVector.begin(); it < enemyFOVVector.end(); it++) {
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

void EnemyFOVpool::initialize(EnemyFOV *enemyFOV, int size)
{
	for (int i = 0; i < size; i++) {
		//enemy->setX(i*TILE_SIZE);
		//enemy->setY(i*TILE_SIZE);
		enemyFOVVector.push_back(*enemyFOV);
		enemyFOV->setActive(true);
		enemyFOV->setVisible(true);
		//put in middle
		//enemyFOV->setX(GAME_WIDTH / 2 - enemyFOV->getWidth() / 2);
		//enemyFOV->setY(GAME_HEIGHT / 2 - enemyFOV->getHeight() / 2);
	}
}

void EnemyFOVpool::update(float frameTime)
{
	for (auto it = enemyFOVVector.begin(); it < enemyFOVVector.end(); it++) {
		it->update(frameTime);
	}

}

void EnemyFOVpool::draw()
{
	for (auto it = enemyFOVVector.begin(); it < enemyFOVVector.end(); it++) {
		if (it->getActive())
			it->draw();
	}
}
