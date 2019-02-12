#pragma once
#include "PlayerState.h"
class Player;
class MovingState :
	public PlayerState
{
private:
	bool moving;
public:
	MovingState();
	~MovingState();

	// Inherited via PlayerState
	virtual void update(Player * player, float frameTime);
	virtual PlayerState* handleInput(Player * player, InputComponent *inputC);
};

