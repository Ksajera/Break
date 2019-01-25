#pragma once
#include "input.h"
#include "Entity.h"
class InputComponent
{
private:
	Input * input;

public:
	InputComponent(Game *gamePtr);
	InputComponent();
	~InputComponent();
	void update(Entity *entity, float frameTime);

};


