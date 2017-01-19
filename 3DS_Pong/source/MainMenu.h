#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <stdlib.h>  
#include <memory> 
#include <vector>

#include "GameState.h"
#include "ButtonManager.h"
#include "Button.h"
#include "ClassicPong.h"
#include "MultiPlayerMenu.h"
#include "HostGame.h"
#include "JoinGame.h"

//assets of the Main Menu
#include "MainMenuAssets\SingleplayerButton.c"
#include "MainMenuAssets\SingleplayerButtonSelected.c"
#include "MainMenuAssets\JoinFriendButton.c"
#include "MainMenuAssets\JoinFriendButtonSelected.c"
#include "MainMenuAssets\HostGameButton.c"
#include "MainMenuAssets\HostGameButtonSelected.c"


/**
*@The SplashScreen of the game!
*/
class MainMenu : public GameState {
private:
	sf2d_texture *topScreen;
	std::vector<Button*> buttons;
	ButtonManager *buttonManager;
	UdpSocket &socket;
	touchPosition touch;
	u32 held, released, pressed;


public:
	//MainMenu(StateManager &manager);
	MainMenu(StateManager &manager,UdpSocket &socket);
	~MainMenu();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};