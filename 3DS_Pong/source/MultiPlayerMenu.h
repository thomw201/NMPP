#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <stdlib.h>  
#include <vector>

#include "GameState.h"
#include "ButtonManager.h"
#include "Button.h"
#include "SplashScreen.h"


//assets of the Main Menu


#include "MainMenuAssets\JoinFriendButton.c"
#include "MainMenuAssets\JoinFriendButtonSelected.c"
#include "MainMenuAssets\HostGameButton.c"
#include "MainMenuAssets\HostGameButtonSelected.c"
#include "MainMenuAssets\BackButton.c"
#include "MainMenuAssets\BackButtonSelected.c"



/**
*@The SplashScreen of the game!
*/
class MultiPlayerMenu : public GameState {
private:
	sf2d_texture *topScreen;
	std::vector<Button*> buttons;
	ButtonManager *buttonManager;
	touchPosition touch;
	u32 held, released, pressed;
	bool touchHold;

public:
	MultiPlayerMenu(StateManager &manager);
	~MultiPlayerMenu();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};