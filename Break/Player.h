#ifndef _PLAYER_H             // Prevent multiple definitions if this 
#define _PLAYER_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "InputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "Weapon.h"
#include "PlayerState.h"
#include "StandingState.h"
#include "CombatState.h"
#include "IdleState.h"
namespace PlayerNS
{
	//const int   WIDTH = 32;                // image width (each frame)
	//const int   HEIGHT = 64;               // image height
	//const int   WIDTH = 32;               // image height
	//const int   HEIGHT = 50;               // image height
	const int   WIDTH = 64;               // image height
	const int   HEIGHT = 64;               // image height
	const int   X = GAME_WIDTH / 2 - WIDTH; // location on screen
	const int   Y = GAME_HEIGHT / 2 - HEIGHT;
}

class Player : public Entity
{
private:
	int animFrame;
public:
	PlayerState * state_;
	CombatState * combat_;
	Player();
	~Player();

	void setPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 getPosition();
	D3DXVECTOR2 direction;
	D3DXVECTOR2 getWeaponPosition();

	InputComponent inputComponent;
	//ShootingComponent shootingComponent; //to be moved into gun class?
	Weapon* weapon;
	PlayerPhysicsComponent physics;

	void scroll();
	void draw();
	void equip(Weapon *w);
	void equip(RangedModel *model);
	void update(float frameTime);
	void handleInput();
	void setAnimFrame(int animFrame);
	void setAnimFrame();

	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
};
#endif

