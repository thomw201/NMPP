#include "SplashScreen.h"

SplashScreen::SplashScreen(StateManager &manager) : GameState(manager)
{
	NF_LoadTiledBg("splash/splashscreenbottom", "bottom_splash", 256, 256); // splash background
	NF_LoadTiledBg("splash/splashscreentop", "top_splash", 256, 256);	//field background

	NF_CreateTiledBg(1, 3, "bottom_splash");		// splash Background
	NF_CreateTiledBg(0, 3, "top_splash");		// game Background
}

SplashScreen::~SplashScreen()
{
	NF_UnloadTiledBg("bottom_splash");
	NF_UnloadTiledBg("top_splash");
	NF_DeleteTiledBg(0, 3);
	NF_DeleteTiledBg(1, 3);
	NF_ResetTiledBgBuffers();
}

void SplashScreen::update(float deltaTime)
{
	while (1)
	{
		if (KEY_START & keysCurrent()) {
			changeState(new PongvsAI(manager));
		}
	}
}


void SplashScreen::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}
