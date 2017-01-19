#include "StateManager.h"
#include "SplashScreen.h"


StateManager::StateManager(UdpSocket & socket) : socket(socket)
{
	currentState = new SplashScreen(*this,socket);
}

StateManager::~StateManager()
{
	delete currentState;
}

void StateManager::update(float deltaTime)
{
	currentState->update(deltaTime);
}

void StateManager::changeState(GameState *nextState)
{
	delete currentState;
	currentState = nextState;
}
