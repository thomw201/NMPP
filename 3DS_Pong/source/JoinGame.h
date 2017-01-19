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



/**
*@The HostScreen of the game of the game!
*/
class JoinGame : public GameState {
private:
	//std::vector<Button*> buttons;
	//ButtonManager *buttonManager;
	touchPosition touch;
	u32 held, released, pressed;
	string message;
	string ip;
	string port;
	string numbers;
	UdpSocket &socket;
	int count;
	volatile bool ipset,portset;
	uiBitmapFont font;

public:
	JoinGame(StateManager &manager, UdpSocket &socket);
	~JoinGame();
	void update(float deltaTime) override;
	void getMessageLoop();

private:
	void changeState(GameState *nextState) override;
	
};
