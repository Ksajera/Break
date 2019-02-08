#pragma once
#include "Ranged.h"
namespace handgunNS {
	static const int MAGAZINE_SIZE = 16;
	static const float RELOAD_DURATION = 1.5f;
	static const int ATTACK_DAMAGE = 5;
	static const float FIRE_RATE = 10.0f;

	//Sprite data
	static const int WIDTH = 12;
	static const int HEIGHT = 8;
	static const int TEXTURE_COLS = 0;

}
class Handgun :
	public Ranged
{
public:
	Handgun();
	~Handgun();
};

