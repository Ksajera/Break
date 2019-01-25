#include "InputComponent.h"

InputComponent::InputComponent(Game *gamePtr)
{
	input = gamePtr->getInput();
}

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::update(Entity *entity, float frameTime)
{
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

	if (direction != D3DXVECTOR2(0, 0))
		entity->setVelocity(velocity + direction * MOVE_SPEED * frameTime);
	else {
		if (velocity != D3DXVECTOR2(0, 0)) {
			D3DXVec2Normalize(&velocity, &velocity);
			entity->setVelocity(entity->getVelocity() - velocity * 180 * frameTime);
		}

	}


}

