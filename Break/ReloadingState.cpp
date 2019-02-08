#include "ReloadingState.h"
#include "IdleState.h"

ReloadingState::ReloadingState(Weapon * weapon) : ShootingState(weapon)
{

}

ReloadingState::ReloadingState(Weapon * weapon, float reloadTimeLeft) : ShootingState(weapon)
{
	this->reloadTimeLeft = reloadTimeLeft;
}

ReloadingState::~ReloadingState()
{

}

void ReloadingState::update(Entity * entity, float frameTime)
{
	reloadTimeLeft -= frameTime;

}

CombatState * ReloadingState::handleInput(Entity * entity, InputComponent * inputC, Weapon* weapon)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
	if (reloadTimeLeft <= 0) {
		if (inputC->getMouseInput(entity, &direction)) {
			return new ShootingState(weapon);
		}
		else
			return new IdleState();
	}

	return new ReloadingState(weapon, reloadTimeLeft);
}
