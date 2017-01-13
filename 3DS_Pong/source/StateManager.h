#pragma once

#include "GameState.h"



/**
*@The game state manager.
*/
class GameState;

class StateManager {
private:
	GameState *currentState;

public:
	StateManager();
	~StateManager();
	void update(float deltaTime);
	void changeState(GameState *nextState);

	
};