#pragma once
#include "entity.h"
#include "InputComponent.h"
#include "Weapon.h"
class CombatState
{
private:
	Weapon* weapon;
public:
	CombatState();
	~CombatState();
	virtual void enter(Entity * entity);
	virtual void exit(Entity * entity);
	virtual void update(Entity * entity, float frameTime) = 0;
	virtual CombatState* handleInput(Entity * entity, InputComponent *inputC, Weapon *weapon) = 0;
};

