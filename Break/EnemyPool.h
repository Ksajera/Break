#pragma once
#include <vector>
#include "game.h"
#include "Enemy.h"

class EnemyPool
{
private:
	std::vector<Enemy> enemyVector;
public:
	EnemyPool();
	~EnemyPool();
	void create(D3DXVECTOR2 position, D3DXVECTOR2 velocity);
	void destroy(std::vector<Enemy>::iterator &it);
	void initialize(Enemy *enemy, int size);
	void update(float frameTime, Player *player);
	void draw();
	void equip(RangedModel *model, std::vector<Enemy>::iterator &it);
	void equip(RangedModel *model, int index);
	void equip(RangedModel *model);
	void collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	std::vector<Enemy>* getEnemies();

};

