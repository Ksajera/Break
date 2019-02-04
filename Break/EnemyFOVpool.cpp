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
		enemyFOVVector.push_back(*enemyFOV);
		enemyFOV->setActive(true);
		enemyFOV->setVisible(true);
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
