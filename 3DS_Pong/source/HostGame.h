#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <stdlib.h>  

#include <string>
#include <functional>

#include "GameState.h"
#include "MultiPlayerMenu.h"
#include "UdpSocket.h"


//assets of the Main Menu





/**
*@The HostScreen of the game of the game!
*/
class HostGame : public GameState {
private:
	//std::vector<Button*> buttons;
	//ButtonManager *buttonManager;
	#define STACKSIZE (4 * 1024)
	touchPosition touch;
	u32 held, released, pressed;
	string message;
	Thread receiveLoop;
	UdpSocket *socket;
	volatile bool received,running;

public:
	HostGame(StateManager &manager);
	~HostGame();
	void update(float deltaTime) override;
	void getMessageLoop();

private:
	void changeState(GameState *nextState) override;
	
};
