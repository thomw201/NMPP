#pragma once
#include <3ds.h>
#include <sf2d.h>
#include "GameState.h"
#include "RainbowTop.c"
#include "RainbowBottom.c"

/**
*@The SplashScreen of the game!
*/
class SplashScreen : public GameState {
private:
	sf2d_texture *topScreen;
	sf2d_texture *botScreen;


public:
	SplashScreen(GameState *currentState);
	~SplashScreen();
	void update(float deltaTime) override;

private:
	void changeState() override;
};