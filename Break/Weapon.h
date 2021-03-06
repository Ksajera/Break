#pragma once
#include "entity.h"
#include <vector>
class Weapon : public Image
{
public:
	Weapon();
	~Weapon();
	D3DXVECTOR2 direction;
	virtual void draw();
	virtual void update(float frameTime);
	virtual bool attack();
	virtual void reload();
	virtual float getAttackSpeed();
	virtual int getDamage();
	virtual bool collide(Entity &entity, D3DXVECTOR2 &collisionVector);
	virtual bool initialize(Graphics *g, int width, int height,
		int ncols, TextureManager *textureM);
	Entity *User;

};

