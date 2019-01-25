#ifndef _PLAYERSHIP_H                 // Prevent multiple definitions if this 
#define _PLAYERSHIP_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace playerShipNS
{

	const int WIDTH = 95;                   // image width
	const int HEIGHT = 101;                  // image height


	const int X = 0;   // location on screen
	const int Y = 0;
	const float ROTATION_RATE = (float)PI / 4; // radians per second
	const float SPEED = 100;                // 100 pixels per second
	const float MASS = 300.0f;              // mass


	const int   TEXTURE_COLS = 4;           // texture has 8 columns
	const int   PLAYERSHIP_START_FRAME = 4;      // playership starts at frame 4
	const int   PLAYERSHIP_END_FRAME = 7;        // playership animation frames 4,5,6,7

	const float INVULN_DURATION = 2.0f;
	const float SHIP_ANIMATION_DELAY = 0.2f;    // time between frames

}

// inherits from Entity class
class PlayerShip : public Entity
{
private:
	float rotation;
	float timer;
public:
	// constructor
	PlayerShip();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	//void hit();

};
#endif