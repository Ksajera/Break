#pragma once
#include "Ranged.h"
namespace rifleNS {
	static const int MAGAZINE_SIZE = 50;
	static const float RELOAD_DURATION = 3.0f;
	static const int ATTACK_DAMAGE = 10;
	static const float FIRE_RATE = 10.0f;

	//Sprite data
	static const int WIDTH = 25;
	static const int HEIGHT = 9;
	static const int TEXTURE_COLS = 0;

}
class Rifle :
	public Ranged
{
public:
	Rifle();
	~Rifle();
};

