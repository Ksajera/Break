#include "WeaponPool.h"



WeaponPool::WeaponPool()
{
}


WeaponPool::~WeaponPool()
{
}

void WeaponPool::create(D3DXVECTOR2 position)
{
	for (auto it = weapons.begin(); it < weapons.end(); it++) {
		if (!(it->getVisible())) {
			it->setVisible(true);
			it->setX(position.x);
			it->setY(position.y);
			return;
		}
	}
}

void WeaponPool::destroy()
{
}

void WeaponPool::destroy(std::vector<Weapon>::iterator & it)
{
	it->setVisible(false);
}

void WeaponPool::initialize(Weapon * weapon, int size)
{
	weapon->setVisible(false);
	for (int i = 0; i < size; i++) {
		weapons.push_back(*weapon);

	}
}

void WeaponPool::update(float frameTime)
{
	for (auto it = weapons.begin(); it < weapons.end(); it++) {
		it->update(frameTime);
	}
}

void WeaponPool::draw()
{
	for (auto it = weapons.begin(); it < weapons.end(); it++) {
		it->draw();
	}
}

void WeaponPool::reload()
{
}
