#pragma once
#include <3ds.h>
#include <sf2d.h>
#include "StateManager.h"

class StateManager;

/**
*@ Abstract Class for a gamestate
*/
class GameState {

protected:
	StateManager &manager;
	virtual void changeState(GameState *nextState) = 0;

public:
	GameState(StateManager &manager) : manager(manager) {}
	virtual ~GameState(){}
	virtual void update(float deltaTime) = 0;
};