#include "ShootingState.h"
#include "ReloadingState.h"
#include "IdleState.h"
#include "Ranged.h"

ShootingState::ShootingState(Weapon * weapon)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
}

ShootingState::ShootingState(Weapon * weapon, float timeLeft)
{
	this->weapon = dynamic_cast<Ranged*>(weapon);
	this->timeLeft = timeLeft;
}

ShootingState::~ShootingState()
{
}

void ShootingState::update(Entity * entity, float frameTime)
{
	timeLeft -= frameTime;
	if (timeLeft <= 0) {
		D3DXVECTOR2 position = D3DXVECTOR2(entity->getCenterX(), entity->getCenterY());
		weapon->attack(position, direction);
	}

}

CombatState * ShootingState::handleInput(Entity * entity, InputComponent * inputC, Weapon *weapon)
{
	if (!inputC->getMouseInput(entity, &direction)) {
		return new IdleState();
	}	

	if (inputC->input->wasKeyPressed('R'))
		return new ReloadingState(weapon);

	return new ShootingState(weapon, timeLeft);
}
