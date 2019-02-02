#pragma once
#include "input.h"
#include "Entity.h"
#include "ShootingComponent.h"
class InputComponent
{
protected:
	Input * input;
	ShootingComponent *sc;

public:
	InputComponent(Game *gamePtr, ShootingComponent * pewpew);
	InputComponent();
	~InputComponent();
	virtual void update(Entity *entity, float frameTime);
	bool getMovement(D3DXVECTOR2* pOut);

};


