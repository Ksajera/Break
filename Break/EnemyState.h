#pragma once
#include "EnemyAI.h"
class Enemy;

class EnemyState
{
public:
	EnemyState();
	~EnemyState();
	//interface functions
	virtual void enter(Enemy* enemy);
	virtual void exit(Enemy* enemy);

	virtual void update(Enemy* enemy, Player* player, EnemyAI* ai, float frameTime) = 0;
	virtual EnemyState* handleEnemy(Enemy* enemy, EnemyAI* ai, float frameTime) = 0;

};

