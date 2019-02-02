#pragma once
#include "entity.h"
#include "InputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "ShootingComponent.h"
#include "PlayerState.h"

class Player : public Entity
{
private:
	InputComponent inputComponent;
	ShootingComponent shootingComponent; //to be moved into gun class?
	PlayerPhysicsComponent physics;
	PlayerState* state_;

public:
	Player();
	~Player();
	void update(float frameTime);
	void setPosition(D3DXVECTOR2 position);
	void handleInput(Input* input);
	D3DXVECTOR2 getPosition();
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, ProjectilePool * pool);
};

