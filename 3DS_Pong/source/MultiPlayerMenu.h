#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <stdlib.h>  
#include <vector>

#include "GameState.h"
#include "ButtonManager.h"
#include "Button.h"
#include "SplashScreen.h"
#include "HostGame.h"


//assets of the Main Menu


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

public:
	MultiPlayerMenu(StateManager &manager);
	~MultiPlayerMenu();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};