#pragma once

#include <stdlib.h>  
#include <memory> 
#include "GameState.h"



/**
*@The SplashScreen of the game!
*/


class SplashScreen : public GameState {
private:

	bool stop = false;

public:
	SplashScreen(StateManager &manager);
	~SplashScreen();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};