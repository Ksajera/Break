#pragma once
#include "InputComponent.h"
class Player; //forward declaration to avoid circular dependency
class StandingState;
class MovingState;

class PlayerState
{
public:
	static StandingState standing;
	static MovingState moving;
	PlayerState();
	~PlayerState();
	//interface functions
	virtual void update(Player* player, float frameTime) = 0;
	virtual PlayerState* handleInput(Player * player, InputComponent *inputC) = 0;

};

