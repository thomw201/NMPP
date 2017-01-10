#pragma once
#include <3ds.h>
#include <sf2d.h>



using namespace std;
/**
*@ Abstract Class for a gamestate
*/
class GameState {

protected:
	GameState *currentState;
	virtual void changeState() = 0;

public:
	GameState(GameState *currentState) : currentState(currentState) {}
	virtual void update(float deltaTime) = 0;
};