#include "Projectile.h"


using namespace ProjectileNS;
Projectile::Projectile() : Entity()
{
	spriteData.width = WIDTH;           // size of EntityPlayer
	spriteData.height = HEIGHT;
	spriteData.x = X;                   // location on screen
	spriteData.y = Y;
	spriteData.rect.bottom = HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = WIDTH;
	edge.top = 0;             // ROTATED_BOX collision edges
	edge.bottom = HEIGHT;
	edge.left = 0;
	edge.right = WIDTH;
	velocity.x = 0;
	velocity.y = 0;
	frameDelay = 0.1f;
	startFrame = 0;     // first frame of animation
	endFrame = cols - 1;     // last frame of animation
	currentFrame = startFrame;
	radius = WIDTH / 2.0;
	collisionType = entityNS::BOX;
}


Projectile::~Projectile()
{
}

void Projectile::update(float frameTime)
{
	physics.update(this, frameTime);
	if (getX() < 0 - getWidth()|| getX() > GAME_WIDTH + getWidth() 
		|| getY() < 0 - getHeight() || getY() > GAME_HEIGHT + getHeight()) 
	{
		setActive(false);
		setVisible(false);
		
	}

}

bool Projectile::initialize(Game * gamePtr, int width, int height, int ncols, TextureManager * textureM)
{
	physics = PhysicsComponent();
	return Entity::initialize(gamePtr, width, height, ncols, textureM);

}

void Projectile::draw()
{
	Image::draw();
}
