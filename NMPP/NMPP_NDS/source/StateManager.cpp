#include "StateManager.h"
#include "SplashScreen.h"
#include "PongvsAI.h"

StateManager::StateManager()
{
	currentState = new SplashScreen(*this);
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
