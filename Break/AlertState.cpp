#include "AlertState.h"



AlertState::AlertState()
{
}


AlertState::~AlertState()
{
}

EnemyState* AlertState::update(Enemy* enemy, float frameTime)
{
	//if player detected, do something
	//	return Other state

	return new AlertState();
}
