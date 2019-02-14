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
	const int TEXTURE_SIZE = 32;
	const int TEXTURE_COLS = 30;
	const int MAP_HEIGHT = 30; //960px
	const int MAP_WIDTH = 60; //1920px
	//const float SCROLL_RATE = 1000;

	const int __ = -1;				//empty tile
	const int W = 210;				//wall tile
	const int D = 191;				//door tile (light sprite)
	const int T = 299;				//obstacle tile (table)
	const int F1 = 234;				//floor tile T
	const int F2 = 237;				//floor tile 2
	const int F3 = 240;				//floor tile 3
	const int F4 = 243;				//floor tile 4
	const int G = 178;				//goal tile

	const int tileMap[MAP_HEIGHT][MAP_WIDTH] = {
	   W, W, W, W, W, W, W, W, W, W, W, W, W,W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
	   W, W, W, W, W, W, W, W, W, W, W, W, W,W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
	   W, W, W, W, W, W, W, W, W, W, W, W, W,W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
		W, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__, W,__,__, W,__,__, T,__,__,__,D,G,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,D,
		W, W, W, W, W, W, W, W, W, W, W, W, W,W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
	    W, W, W, W, W, W, W, W, W, W, W, W, W,W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
	    W, W, W, W, W, W, W, W, W, W, W, W, W,W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
	};
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
