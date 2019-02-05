#pragma once
#include "image.h"
#include "ShootingComponent.h"
class Weapon : Image
{
public:
	Weapon();
	~Weapon();
	void draw();
	void update(float frameTime);

};

