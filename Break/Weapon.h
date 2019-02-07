#pragma once
#include "entity.h"
#include <vector>
class Weapon : public Image
{
public:
	Weapon();
	~Weapon();
	virtual void draw();
	virtual void update(float frameTime);
	virtual void attack();
	virtual void attack(D3DXVECTOR2 position, D3DXVECTOR2 direction);
	virtual float getAttackSpeed();
	virtual bool collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	virtual bool initialize(Graphics *g, int width, int height,
		int ncols, TextureManager *textureM);

};

