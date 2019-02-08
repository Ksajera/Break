#pragma once
#include "EnemyState.h"

class AlertState;

class PatrolState :
	public EnemyState
{
private:
	EnemyAI* enemyAI;
public:
	PatrolState();
	PatrolState(EnemyAI* ai);
	~PatrolState();

	// Inherited via EnemyState
	virtual void enter(Enemy* enemy) override;
	virtual void exit(Enemy* enemy) override;
	virtual void update(Enemy * enemy, Player* player, EnemyAI* ai, float frameTime) override;
	virtual EnemyState * handleEnemy(Enemy * enemy, EnemyAI * ai) override;

	void PatrolState::movementUpdate(Enemy* enemy, EnemyAI* ai);

};

