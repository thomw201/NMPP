#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <stdlib.h>  

#include <string>
#include <sstream>

#include "GameState.h"
#include "MultiPlayerMenu.h"
#include "HostPong.h"
#include "UdpSocket.h"
#include "TextPrinter.h"


//assets of the hostGame
#include "Font.c"





/**
*@The HostScreen of the game of the game!
*/
class HostGame : public GameState {
private:
	//std::vector<Button*> buttons;
	//ButtonManager *buttonManager;
	touchPosition touch;
	u32 held, released, pressed;
	string message;
	string ip;
	string port;
	Thread receiveLoop;
	UdpSocket &socket;
	volatile bool received,running;
	uiBitmapFont font;

public:
	HostGame(StateManager &manager, UdpSocket &socket);
	~HostGame();
	void update(float deltaTime) override;
	void getMessageLoop();

private:
	void changeState(GameState *nextState) override;
	
};
