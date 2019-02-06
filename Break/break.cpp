// Programming 2D Games
// Copyright (c) 2011 by:
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "break.h"

//=============================================================================
// Constructor
//=============================================================================
Break::Break()
{}

//=============================================================================
// Destructor
//=============================================================================
Break::~Break()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Break::initialize(HWND hwnd)
{
  Game::initialize(hwnd); // throws GameError
	world.initialize(graphics);

	#pragma region Initialization

	//BACKGROUND
	if (!bgTexture.initialize(graphics, NEBULA_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));
	if (!bgImage.initialize(graphics, 0, 0, 0, &bgTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

	//BULLET
	if (!bulletSprite.initialize(graphics, BULLET_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet texture."));
	if (!bullet.initialize(this, 8, 8, 0, &bulletSprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet."));

	if (!handgunSprite.initialize(graphics, HANDGUN_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing handgun texture."));

	if (!handgun.initialize(graphics, handgunNS::WIDTH, handgunNS::HEIGHT, handgunNS::TEXTURE_COLS, &handgunSprite, &bullet, handgunNS::MAGAZINE_SIZE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet."));

	//Sprites
	if (!playerSprite.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture."));

	//Entities
	if (!player.initialize(this, 32, 64, 0, &playerSprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player."));

	player.equip(&handgun);

	//ENEMY
	if (!enemySprite.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy texture."));
	if (!enemy.initialize(this, 64, 64, 0, &enemySprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy."));

	enemy.setActive(false);
	enemy.setVisible(false);

	bulletPool.initialize(&bullet, MAX_PROJECTILES);
	enemyPool.initialize(&enemy, 5);
	enemyPool.create(D3DXVECTOR2(GAME_WIDTH / 2, GAME_HEIGHT / 2), D3DXVECTOR2(0, 0));
    return;

#pragma endregion

}

//=============================================================================
// Update all game items
//=============================================================================
void Break::update()
{
	player.update(frameTime);
	//enemy.update(frameTime); //dk if can comment this out too lazy to find out. but prob no need this line 
	bulletPool.update(frameTime);
	enemyPool.update(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Break::ai()
{

}

//=============================================================================
// Handle collisions
//=============================================================================
void Break::collisions()
{
    VECTOR2 collisionVector;
	std::vector<Enemy>* enemies = enemyPool.getEnemies();
	for (auto it = enemies->begin(); it < enemies->end(); it++) {
		if (player.weapon->collide(*it, collisionVector)) {
			enemyPool.destroy(it);
		}

	}

}

//=============================================================================
// Render game items
//=============================================================================
void Break::render()
{
    graphics->spriteBegin();                // begin drawing sprites
	world.draw();
	bgImage.draw();
	player.draw();
	//enemy.draw();
	bulletPool.draw();
	enemyPool.draw();

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Break::releaseAll()
{
	bgTexture.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Break::resetAll()
{
	bgTexture.onResetDevice();
    Game::resetAll();
    return;
}
