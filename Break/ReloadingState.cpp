#include "ReloadingState.h"
#include "IdleState.h"

ReloadingState::ReloadingState(Weapon * weapon) : ShootingState(weapon)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
	reloadTimeLeft = this->weapon->getReloadDuration();
}

ReloadingState::ReloadingState(Weapon * weapon, float reloadTimeLeft) : ShootingState(weapon)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
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
	if (reloadTimeLeft <= 0) {
		weapon->reload();
		if (inputC->getMouseInput(entity, &weapon->direction)) {
			return new ShootingState(weapon);
		}
		else
			return new IdleState();
	}

	return new ReloadingState(weapon, reloadTimeLeft);
}
