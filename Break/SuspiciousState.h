#pragma once
#include "EnemyState.h"

class SuspiciousState :
	public EnemyState
{
private:
	EnemyAI* enemyAI;
	float countUpIgnore, countUpAlert;
public:
	SuspiciousState();
	SuspiciousState(EnemyAI* ai);
	~SuspiciousState();

	// Inherited via EnemyState
	virtual void update(Enemy * enemy, Player * player, EnemyAI * ai, float frameTime) override;
	virtual EnemyState * handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime) override;
};

