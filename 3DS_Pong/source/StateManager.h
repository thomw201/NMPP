#pragma once

#include "GameState.h"
#include "UdpSocket.h"



//forward declaration of Gamestate.
class GameState;

/**
*@The game state manager.
*/
class StateManager {
private:
	GameState *currentState;
	UdpSocket &socket;

public:
	StateManager(UdpSocket &socket);
	~StateManager();
	void update(float deltaTime);
	void changeState(GameState *nextState);

};