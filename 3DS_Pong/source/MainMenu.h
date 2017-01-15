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

//assets of the Main Menu
#include "MainMenuAssets\SingleplayerButton.c"
#include "MainMenuAssets\SingleplayerButtonSelected.c"
#include "MainMenuAssets\MultiplayerButton.c"
#include "MainMenuAssets\MultiplayerButtonSelected.c"
#include "MainMenuAssets\OptionsButton.c"
#include "MainMenuAssets\OptionsButtonSelected.c"


/**
*@The SplashScreen of the game!
*/
class MainMenu : public GameState {
private:
	sf2d_texture *topScreen;
	std::vector<Button*> buttons;
	ButtonManager *buttonManager;
	touchPosition touch;
	u32 held, released, pressed;

public:
	MainMenu(StateManager &manager);
	~MainMenu();
	void update(float deltaTime) override;

private:
	void changeState(GameState *nextState) override;
};