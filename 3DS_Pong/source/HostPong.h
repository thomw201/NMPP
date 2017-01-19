#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <memory> 
#include "GameState.h"
#include "GameController.h"
#include "SplashScreen.h"
#include "ScoreManager.h"
#include "TextPrinter.h"



/**
*@The SplashScreen of the game!
*/
class HostPong : public GameState {
private:

	GameController game;
	//ScoreManager scoreManager;
	touchPosition touch;
	circlePosition circle;
	u32 held;
	UdpSocket &socket;
	uiBitmapFont font;
	stringstream converter;

public:
	
	HostPong(StateManager &manager, UdpSocket &socket);
	~HostPong();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
	int translateCoordX(int coord);
	int translateCoord(int coord);
};