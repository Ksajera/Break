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
	if (!playerSprite.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture."));

	if (!player.initialize(this, 32, 64, 0, &playerSprite))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player."));

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Break::update()
{
	player.update(frameTime);
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

    
}

//=============================================================================
// Render game items
//=============================================================================
void Break::render()
{
    graphics->spriteBegin();                // begin drawing sprites
	world.draw();
	player.draw();

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Break::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Break::resetAll()
{
    Game::resetAll();
    return;
}
