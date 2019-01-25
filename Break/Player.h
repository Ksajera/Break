#pragma once
#include "entity.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

class Player : public Entity
{
private:
	InputComponent inputComponent;
	PhysicsComponent physicsComponent;
public:
	Player();
	~Player();
	void update(float frameTime);
	void setPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 getPosition();
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
};

