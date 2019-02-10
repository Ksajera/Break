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
	TextureManager bgTexture, playerSprite, enemySprite, bulletSprite, enemyFovSprite, handgunSprite, rifleSprite;
	Image bgImage, enemyFovImage;
	RangedModel pistol, rifleModel;
	Ranged* handgun, *rifle;

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
