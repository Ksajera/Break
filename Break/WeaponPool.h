#pragma once
#include <vector>
#include "Weapon.h"
class WeaponPool
{
private:
	std::vector<Weapon> weapons;
public:
	WeaponPool();
	~WeaponPool();
	void create(D3DXVECTOR2 position);
	void destroy(); //destroy first active
	void destroy(std::vector<Weapon>::iterator &it);
	void initialize(Weapon *weapon, int size);
	void update(float frameTime);
	void draw();
	void reload();

};

