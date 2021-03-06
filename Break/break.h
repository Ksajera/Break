// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _BREAK_H             // Prevent multiple definitions if this 
#define _BREAK_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "World.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "textDX.h"
#include "Projectile.h"
#include "ProjectilePool.h"
#include "EnemyPool.h"
#include "Handgun.h"
#include "Rifle.h"
#include "WeaponPool.h"
#include "RangedModel.h"

namespace breakNS
{
	//const int TEXTURE_SIZE = 32;
	//const int TEXTURE_COLS = 30;
	//const int MAP_HEIGHT = 30; //960px
	//const int MAP_WIDTH = 80; //2560
	////const float SCROLL_RATE = 1000;

	//const int __ = -1;				//empty tile
	//const int W = 213;				//wall tile
	//const int D = 230;				//door tile (light sprite)
	//const int T = 335;				//obstacle tile (table)
	//const int F1 = 340;				//floor tile T
	//const int F2 = 343;				//floor tile 2
	//const int F3 = 346;				//floor tile 3
	//const int F4 = 349;				//floor tile 4
	//const int G = 178;				//goal tile

	//const int tileMap[MAP_HEIGHT][MAP_WIDTH] = {
	//W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,
	//W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,
	//W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,
	//F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,
	//F2,F2,340,F2,F2,F2,F2,F2,340,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,
	//F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F2,
	//F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,
	//F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,
	//F2,F2,F2,F2,F2,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F2,F3,F3,F2,F2,F2,F2,F2,F2,F2,F3,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F4,F4,F4,F2,
	//F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F2,F1,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F4,F2,F2,F2,F2,F2,F4,F2,F4,F4,F2,F2,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,D,D,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,
	//F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F2,F2,F1,F1,F1,F1,F4,F4,F1,F1,F1,F4,F4,F2,F2,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,
	//F1,F1,F1,D,D,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,
	//F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F3,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,D,F1,F1,F1,F1,T,T,T,T,T,F1,F1,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,D,F1,F1,F1,D,F1,D,F1,F1,F1,F1,T,G,T,G,T,F1,F1,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,D,F1,F1,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,D,D,F1,F1,F1,F1,T,T,G,T,T,F1,F1,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,D,D,F1,F1,F1,F1,D,D,D,F1,F2,F2,F1,D,D,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,T,G,T,G,T,F1,F1,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F3,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F1,F1,F1,F1,D,D,D,F1,F2,F1,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F1,T,T,T,T,T,F1,F1,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F3,F3,F3,F3,F3,F3,F2,F2,F1,F1,F1,F1,F1,F2,F2,D,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,
	//F1,F1,F1,F1,F1,F1,F1,F1,D,F1,F2,F1,F1,F1,F1,F1,F1,F3,F2,F2,F2,F2,F3,F3,F3,F2,F2,F2,F2,F2,F2,F2,F3,F3,F1,F1,F1,F1,F2,F1,D,D,F1,F1,F1,F3,F1,F1,F1,F1,F1,F1,F2,F2,F1,F1,F4,F4,F1,F1,F1,F1,F1,F1,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,
	//F1,F1,F1,F1,F2,F2,F2,F2,D,D,D,D,F2,F2,F3,F3,F3,F2,F2,F2,F3,F3,F1,F1,F2,F2,F2,F1,F1,F3,F3,F3,F3,F3,F3,F3,F3,F3,F3,D,D,F3,F3,F2,F2,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,F1,
	//F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,
	//F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,
	//F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F1,F2,F1,F2,F2,F2,F1,F4,F1,F2,F2,F2,F2,
	//F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,F1,F2,F2,F2,F2,F2,
	//F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,F2,
	//W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,
	//W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,W,F4,F4,W,W,F4,W,
	//W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W
	//};
}
//=============================================================================
// This class is the core of the game
//=============================================================================
class Break : public Game
{
private:
    // game items
	World world;
	Player player;
	Enemy enemy;
	Projectile bullet;
	ProjectilePool bulletPool;
	EnemyPool enemyPool;
	WeaponPool weaponPool;
	TextureManager bgTexture, playerSprite, enemySprite, bulletSprite, enemyFovSprite, handgunSprite, rifleSprite, tileSheet;
	Image bgImage, enemyFovImage, tileImage;
	RangedModel pistol, rifleModel;
	Ranged* handgun, *rifle;
	float mapX, mapY;

public:
    // Constructor
    Break();

    // Destructor
    virtual ~Break();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
};

#endif
