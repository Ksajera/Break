#pragma once
#include <vector>
#include "Weapon.h"
class WeaponPool
{
public:
	std::vector<Weapon> weapons;
	WeaponPool();
	~WeaponPool();
	void create(D3DXVECTOR2 position);
	void destroy(); //destroy first active
	void destroy(std::vector<Weapon>::iterator &it);
	void initialize(Weapon *weapon[], int size);
	void add(Weapon *weapon);
	void update(float frameTime);
	void draw();
	void reload();

};

