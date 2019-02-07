#pragma once
#include "EnemyState.h"
class AlertState :
	public EnemyState
{
public:
	AlertState();
	~AlertState();
	virtual EnemyState* update(Enemy* enemy, float frameTime);
};

