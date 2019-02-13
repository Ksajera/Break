#pragma once
#include "EnemyState.h"
class EnemyIdleState :
	public EnemyState
{
private:
	EnemyAI* enemyAI;
public:
	EnemyIdleState();
	EnemyIdleState(Enemy* enemy, EnemyAI* ai);
	~EnemyIdleState();

	// Inherited via EnemyState
	virtual void enter(Enemy *enemy);
	virtual void exit(Enemy *enemy);
	virtual void update(Enemy * enemy, Player * player, EnemyAI * ai, float frameTime) override;
	virtual EnemyState * handleEnemy(Enemy * enemy, EnemyAI * ai, float frameTime) override;

	void randomDirection(Enemy* enemy, float frameTime);

};

