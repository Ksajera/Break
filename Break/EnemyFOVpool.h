#pragma once
#include <vector>
#include "game.h"
#include "EnemyFOV.h"

class EnemyFOVpool
{
private:
	std::vector<EnemyFOV> enemyFOVVector;
public:
	EnemyFOVpool();
	~EnemyFOVpool();
	void create(D3DXVECTOR2 position, D3DXVECTOR2 velocity);
	void initialize(EnemyFOV *enemyFOV, int size);
	void update(float frameTime);
	void draw();
};

