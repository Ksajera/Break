#include "EnemyState.h"



EnemyState::EnemyState()
{
}


EnemyState::~EnemyState()
{
}

void EnemyState::enter(Enemy* enemy)
{
}

void EnemyState::exit(Enemy* enemy)
{
}

int EnemyState::MIN_MAX_RAND(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
