#include "StateManager.h"
#include "SplashScreen.h"

StateManager::StateManager()
{
	currentState = new ClassicPong(*this);
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
