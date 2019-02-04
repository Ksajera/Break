#pragma once
#include <vector>
#include "entity.h"
#include "Enemy.h"

class EnemyFOV : public Entity
{
private:
	Enemy *enemy;

public:
	EnemyFOV();
	~EnemyFOV();
	//D3DXVECTOR2 getPosition();
	//void setPosition(D3DXVECTOR2 position);
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void draw();

};

