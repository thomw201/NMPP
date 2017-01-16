#pragma once
#include "GameState.h"
#include <nf_lib.h>
#include "MainMenu.h"


/**
*@The SplashScreen of the game!
*/


class SplashScreen : public GameState {
public:
	SplashScreen(StateManager &manager);
	~SplashScreen();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};