#pragma once
class Enemy;

class EnemyState
{
public:
	EnemyState();
	~EnemyState();
	//interface functions
	virtual EnemyState* update(Enemy* enemy, float frameTime) = 0;

};

