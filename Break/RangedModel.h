#pragma once
#include "graphics.h"
#include "Projectile.h"
#include "textureManager.h"
class Ranged;
class RangedModel
{
private:
	int MAGAZINE_SIZE;
	float RELOAD_DURATION;
	int ATTACK_DAMAGE;
	float FIRE_RATE;

	//Sprite data
	int WIDTH;
	int HEIGHT;
	int TEXTURE_COLS;

	Projectile * PROJECTILE;
	TextureManager * TEXTUREM;


public:
	Ranged* newRanged(Graphics *g);
	int getClipSize() { return MAGAZINE_SIZE; }
	float getReloadTime() { return RELOAD_DURATION; }
	int getDamage() { return ATTACK_DAMAGE; }
	float getFireRate() { return FIRE_RATE; }

	Projectile* getProjectile() { return PROJECTILE; }
	TextureManager* getTextureM() { return TEXTUREM; }

	int getWidth() { return WIDTH; }
	int getHeight() { return HEIGHT; }
	int getCols() { return TEXTURE_COLS; }

	RangedModel(Projectile* projectile, TextureManager* textureM, 
		int clipSize, float reloadTime, int damage, float fireRate, int width, int height, int cols);
	RangedModel();
	~RangedModel();

};

