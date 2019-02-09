#include "RangedModel.h"
#include "Ranged.h"

Ranged * RangedModel::newRanged(Graphics * g)
{
	Ranged *newRanged = new Ranged();
	newRanged->initialize(g, *this);
	return newRanged;
}

RangedModel::RangedModel(Projectile * projectile, TextureManager * textureM, int clipSize, float reloadTime, int damage, float fireRate, int width, int height, int cols)
{
	PROJECTILE = projectile;
	TEXTUREM = textureM;
	MAGAZINE_SIZE = clipSize;
	RELOAD_DURATION = reloadTime;
	ATTACK_DAMAGE = damage;
	FIRE_RATE = fireRate;
	WIDTH = width;
	HEIGHT = height;
	TEXTURE_COLS = cols;
}

RangedModel::RangedModel()
{
}

RangedModel::~RangedModel()
{
}
