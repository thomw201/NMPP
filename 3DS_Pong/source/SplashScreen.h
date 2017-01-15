#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <stdlib.h>  
#include <memory> 
#include "GameState.h"
#include "MainMenu.h"

#include "MainMenuAssets\PressStartScreen.c"
#include "MainMenuAssets\SplashScreen.c"


/**
*@The SplashScreen of the game!
*/


class SplashScreen : public GameState {
private:
	sf2d_texture *topScreen;
	sf2d_texture *botScreen;
	u32 held;

public:
	SplashScreen(StateManager &manager);
	~SplashScreen();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};