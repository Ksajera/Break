#include "playerShip.h"

//=============================================================================
// default constructor
//=============================================================================
PlayerShip::PlayerShip() : Entity()
{
	spriteData.width = playerShipNS::WIDTH;           // size of player ship
	spriteData.height = playerShipNS::HEIGHT;
	spriteData.x = playerShipNS::X;                   // location on screen
	spriteData.y = playerShipNS::Y;
	spriteData.rect.bottom = playerShipNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = playerShipNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	rotation = 0.0f;
	frameDelay = playerShipNS::SHIP_ANIMATION_DELAY;
	startFrame = playerShipNS::PLAYERSHIP_START_FRAME;     // first frame of ship animation
	endFrame = playerShipNS::PLAYERSHIP_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = playerShipNS::WIDTH / 2.0;
	mass = playerShipNS::MASS;
	collisionType = entityNS::CIRCLE;
	spriteData.scale = 0.5;
	timer = playerShipNS::INVULN_DURATION;

}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool PlayerShip::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void PlayerShip::draw()
{

	//spriteData.scale = 0.5;

	Image::draw();              // draw ship


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void PlayerShip::update(float frameTime)
{	

	if (!active) {
		timer -= frameTime;
		if (timer <= 0) {
			active = true;
			timer = playerShipNS::INVULN_DURATION;
		}
	}

	if (input->isKeyDown(FORWARD_KEY)) {
		velocity.x += (float)sin(spriteData.angle) * playerShipNS::SPEED * frameTime;
		velocity.y -= (float)cos(spriteData.angle) * playerShipNS::SPEED * frameTime;
	}

	else if (input->isKeyDown(BACKWARD_KEY)) {
		velocity.x -= (float)sin(spriteData.angle) * playerShipNS::SPEED * frameTime;
		velocity.y += (float)cos(spriteData.angle) * playerShipNS::SPEED * frameTime;
	}

	Entity::update(frameTime);

	if (input->isKeyDown(ROTATE_LEFT_KEY)) {
		rotation -= playerShipNS::ROTATION_RATE * frameTime;
	}

	else if (input->isKeyDown(ROTATE_RIGHT_KEY)) {
		rotation += playerShipNS::ROTATION_RATE * frameTime;
	}

	spriteData.angle += frameTime * rotation;   // apply rotation

	spriteData.x += frameTime * velocity.x;         // move ship along X 
	spriteData.y += frameTime * velocity.y;         // move ship along Y

	// Bounce off walls
	if (spriteData.x > GAME_WIDTH - playerShipNS::WIDTH*spriteData.scale)    // if hit right screen edge
	{
		spriteData.x = GAME_WIDTH - playerShipNS::WIDTH*spriteData.scale;    // position at right screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	else if (spriteData.x < 0)                    // else if hit left screen edge
	{
		spriteData.x = 0;                           // position at left screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	if (spriteData.y > GAME_HEIGHT - playerShipNS::HEIGHT*spriteData.scale)  // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - playerShipNS::HEIGHT*spriteData.scale;  // position at bottom screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}


}

