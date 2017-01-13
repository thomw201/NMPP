#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <memory> 
#include "GameState.h"
#include "GameController.h"
#include "SplashScreen.h"


/**
*@The SplashScreen of the game!
*/
class ClassicPong : public GameState {
private:

	GameController game;
	touchPosition touch;
	circlePosition circle;
	u32 held;

public:
	ClassicPong(StateManager &manager);
	~ClassicPong();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};