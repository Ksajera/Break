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
		enemy->setX(i*TILE_SIZE);
		enemy->setY(i*TILE_SIZE);

		enemy->setDirection(RIGHT);
		enemy->setRadians(enemy->getDirection() * PI / 180); //convert degree(direction) to rad
		enemy->setVelo(D3DXVECTOR2(1000, 1));
		enemyVector.push_back(*enemy);
		enemyVector[i].initState();
	}
}

void EnemyPool::destroy(std::vector<Enemy>::iterator &it) {
	it->setActive(false);
	it->setVisible(false);
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

void EnemyPool::collide(Entity &entity, D3DXVECTOR2 &collisionVector)
{
	for (auto it = enemyVector.begin(); it < enemyVector.end(); it++) {
		if (it->getActive()) {
			if (it->collidesWith(entity, collisionVector)) {
				destroy(it);
				return;
			}
		}
	}
}

std::vector<Enemy>* EnemyPool::getEnemies()
{
	return &enemyVector;
}
