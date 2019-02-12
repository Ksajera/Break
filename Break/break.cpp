// Programming 2D Games
// Copyright (c) 2011 by:
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "break.h"
using namespace breakNS;

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
	/*if (!bgTexture.initialize(graphics, NEBULA_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));
	if (!bgImage.initialize(graphics, 0, 0, 0, &bgTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));*/

	//TILEMAP 
	if (!tileSheet.initialize(graphics, TILE_MAP_IMAGE))				//Tile Sheet
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading tile sheet"));
	if (!tileImage.initialize(graphics, TILE_SIZE, TILE_SIZE, 35, &tileSheet))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tile"));

	//BULLET
	if (!bulletSprite.initialize(graphics, BULLET_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet texture."));
	if (!bullet.initialize(this, 8, 8, 0, &bulletSprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet."));

	if (!handgunSprite.initialize(graphics, HANDGUN_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing handgun texture."));

	//if (!handgun.initialize(graphics, handgunNS::WIDTH, handgunNS::HEIGHT, handgunNS::TEXTURE_COLS, &handgunSprite, &bullet, handgunNS::MAGAZINE_SIZE, handgunNS::RELOAD_DURATION, handgunNS::FIRE_RATE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet."));

	if (!rifleSprite.initialize(graphics, RIFLE_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing handgun texture."));

	//if (!rifle.initialize(graphics, rifleNS::WIDTH, rifleNS::HEIGHT, rifleNS::TEXTURE_COLS, &rifleSprite, &bullet, rifleNS::MAGAZINE_SIZE, rifleNS::RELOAD_DURATION, rifleNS::FIRE_RATE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bullet."));

	pistol = RangedModel(&bullet, &handgunSprite, 24, 1.5f, 20, 2.0f, 12, 8, 0);
	rifleModel = RangedModel(&bullet, &rifleSprite, 64, 3.0f, 10, 12.0f, 25, 9, 0);
	
	handgun = pistol.newRanged(graphics);
	rifle = rifleModel.newRanged(graphics);

	//Sprites
	if (!playerSprite.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture."));

	//Entities
	if (!player.initialize(this, PlayerNS::WIDTH, PlayerNS::HEIGHT, 9, &playerSprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player."));

	//player.equip(rifle);
	player.equip(&rifleModel);

	//ENEMY
	if (!enemySprite.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy texture."));
	if (!enemy.initialize(this, EnemyNS::WIDTH, EnemyNS::HEIGHT, 0, &enemySprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy."));

	//setframe
	player.setCurrentFrame(DOWN_START_FRAME);
	player.setFrames(0, 8);

	//bulletPool.initialize(&bullet, MAX_PROJECTILES);
	enemyPool.initialize(&enemy, 2);
	enemyPool.equip(&pistol);
	//enemyPool.create(D3DXVECTOR2(GAME_WIDTH / 2, GAME_HEIGHT / 2), D3DXVECTOR2(0, 0));

    return;

#pragma endregion

}

//=============================================================================
// Update all game items
//=============================================================================
void Break::update()
{
	float playerX;
	player.update(frameTime);
	bulletPool.update(frameTime);
	enemyPool.update(frameTime, &player);
	//enemy.update(frameTime, &player);

	//playerX = player.getX();
	//if (playerX < 0)                  // if butterfly off screen left
	//{
	//	mapX -= player.getVelocity().x * frameTime;  // scroll map right
	//	player.setX(0);              // put butterfly at left edge
	//}
	//// if butterfly off screen right
	//else if (playerX > GAME_WIDTH - player.getWidth())
	//{
	//	mapX -= player.getVelocity().x * frameTime;  // scroll map left
	//	// put butterfly at right edge
	//	player.setX((float)(GAME_WIDTH - player.getWidth()));
	//}

	//if (mapX > 0)    // if map past left edge
	//{
	//	mapX = 0;   // stop at left edge of map
	//	player.setVelocity(D3DXVECTOR2(0, 0));  // stop butterfly
	//}
	//// if map past right edge
	//else if (mapX < (-MAP_WIDTH * TEXTURE_SIZE) + GAME_WIDTH)
	//{
	//	// stop at right edge of map
	//	mapX = (-MAP_WIDTH * TEXTURE_SIZE) + GAME_WIDTH;
	//	player.setVelocity(D3DXVECTOR2(0,0));  // stop butterfly
	//}
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
			it->damage(player.weapon->getDamage());
		}

	}

}

//=============================================================================
// Render game items
//=============================================================================
void Break::render()
{
    graphics->spriteBegin();                // begin drawing sprites

	//for (int row = 0; row < MAP_HEIGHT; row++)       // for each row of map
	//{
	//	tileImage.setY((float)(row*TEXTURE_SIZE)); // set tile Y
	//	for (int col = 0; col < MAP_WIDTH; col++)    // for each column of map
	//	{
	//		if (tileMap[row][col] >= 0)          // if tile present
	//		{
	//			tileImage.setCurrentFrame(tileMap[row][col]);    // set tile texture
	//			tileImage.setX((float)(col*TEXTURE_SIZE) + mapX);   // set tile X
	//			//tileImage.setY((float)(col*TEXTURE_SIZE) + mapY);   // set tile Y
	//			// if tile on screen
	//			if (tileImage.getX() > -TEXTURE_SIZE && tileImage.getX() < GAME_WIDTH)
	//				tileImage.draw();                // draw tile
	//			/*if (tileImage.getY() > -TEXTURE_SIZE && tileImage.getY() < GAME_HEIGHT)
	//				tileImage.draw();      */          // draw tile
	//		}
	//	}
	//}

	world.draw();
	bgImage.draw();
	player.draw();
	//enemy.draw();
	bulletPool.draw();
	enemyPool.draw();
	//enemy.draw();

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
