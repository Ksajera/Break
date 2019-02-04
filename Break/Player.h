#ifndef _PLAYER_H             // Prevent multiple definitions if this 
#define _PLAYER_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "InputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "ShootingComponent.h"
#include "PlayerState.h"
#include "StandingState.h"
#include "IdleState.h"

class Player : public Entity
{
public:
	PlayerState * state_;
	PlayerState * combat_;
	Player();
	~Player();

	void setPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 getPosition();
	D3DXVECTOR2 direction;
	D3DXVECTOR2 aimDirection;

	InputComponent inputComponent;
	ShootingComponent shootingComponent; //to be moved into gun class?
	PlayerPhysicsComponent physics;

	void scroll();
	void draw();
	void update(float frameTime);
	void handleInput();

	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, ProjectilePool * pool);
};
#endif

