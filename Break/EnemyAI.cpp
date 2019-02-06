#include "EnemyAI.h"



EnemyAI::EnemyAI()
{
	//velo = D3DXVECTOR2(1, 0);
}


EnemyAI::~EnemyAI()
{
}

/*void EnemyAI::update(Enemy *enemy, PhysicsComponent physicsComponent, float frameTime)
{

	enemy->setVelocity(velo);

	if (enemy->getX() + enemy->getWidth() > GAME_WIDTH) {
		enemy->setX(GAME_WIDTH - enemy->getWidth());
	}

	if (enemy->getX() < 0) {
		enemy->setX(0);
	}

	if (enemy->getY() + enemy->getHeight() > GAME_HEIGHT){
		enemy->setY(GAME_HEIGHT - enemy->getHeight());
	}

	if (enemy->getY() < 0) {
		enemy->setY(0);
	}
}
*/