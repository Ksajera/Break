#ifndef _PLAYER_H             // Prevent multiple definitions if this 
#define _PLAYER_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "InputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "ShootingComponent.h"
#include "PlayerState.h"

class Player : public Entity
{
private:
	InputComponent inputComponent;
	ShootingComponent shootingComponent;
	PlayerPhysicsComponent physics;
	PlayerState* state;

public:
	Player();
	~Player();
	void update(float frameTime);
	void setPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 getPosition();
	void draw();
	void scroll();
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, ProjectilePool * pool);
};
#endif

