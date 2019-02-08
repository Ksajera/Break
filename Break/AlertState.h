#pragma once
#include "EnemyState.h"

class PatrolState;

class AlertState :
	public EnemyState
{
public:
	AlertState();
	~AlertState();

	// Inherited via EnemyState
	virtual void enter(Enemy* enemy) override;
	virtual void exit(Enemy* enemy) override;
	virtual void update(Enemy * enemy, Player* player, EnemyAI* ai, float frameTime) override;
	virtual EnemyState * handleEnemy(Enemy * enemy, EnemyAI * ai) override;

	void chasePlayer(Enemy* enemy, Player* player);
};

