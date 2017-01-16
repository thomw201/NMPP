#pragma once

#include "GameState.h"



//forward declaration of Gamestate.
class GameState;

/**
*@The game state manager.
*/
class StateManager {
private:
	GameState *currentState;

public:
	StateManager();
	~StateManager();
	void update(float deltaTime);
	void changeState(GameState *nextState);

};