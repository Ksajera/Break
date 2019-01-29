#include "InputComponent.h"

InputComponent::InputComponent(Game *gamePtr, ShootingComponent *pewpew)
{
	input = gamePtr->getInput();
	sc = pewpew;
}

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::update(Entity *entity, float frameTime)
{
	//Movement Controller
	D3DXVECTOR2 direction = D3DXVECTOR2(0, 0);
	D3DXVECTOR2 velocity = entity->getVelocity();
	if (input->isKeyDown('D'))
		direction.x = 1;
	else if (input->isKeyDown('A'))
		direction.x = -1;
	if (input->isKeyDown('S'))
		direction.y = 1;
	else if (input->isKeyDown('W'))
		direction.y = -1;

	//if keys are pressed
	if (direction != D3DXVECTOR2(0, 0))
		entity->setVelocity(velocity + direction * MOVE_SPEED * frameTime);
	else { //no keys are pressed
		if (velocity != D3DXVECTOR2(0, 0)) {
			D3DXVec2Normalize(&velocity, &velocity);
			entity->setVelocity(entity->getVelocity() - velocity * 180 * frameTime); //decelerate, pseudo lerp

		}

	}

	D3DXVECTOR2 mousePos;
	D3DXVECTOR2 position;
	D3DXVECTOR2 aimDirection;

	mousePos.x = input->getMouseX();
	mousePos.y = input->getMouseY();

	position.x = entity->getCenterX();
	position.y = entity->getCenterY();

	aimDirection = mousePos - position;
	D3DXVec2Normalize(&aimDirection, &aimDirection);

	if (input->getMouseLButton()) {
		sc->fire(position, aimDirection);

	}

}

