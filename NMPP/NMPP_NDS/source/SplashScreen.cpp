#include "SplashScreen.h"

SplashScreen::SplashScreen(StateManager &manager) : GameState(manager)
{
	//NF_LoadTiledBg("splash/splashscreenbottom", "bottom_splash", 256, 256); // splash background
	//NF_LoadTiledBg("splash/splashscreentop", "top_splash", 256, 256);	//field background
	NF_Load16bitsBg("bg/splash", 3);
	NF_Load16bitsBg("bg/pressstart", 4);
	//NF_CreateTiledBg(1, 3, "bottom_splash");		// splash Background
	//NF_CreateTiledBg(0, 3, "top_splash");		// game Background
	NF_Copy16bitsBuffer(0, 3, 3);
	NF_Copy16bitsBuffer(1, 4, 4);
	// Manda el backbuffer a la pantalla

}

SplashScreen::~SplashScreen()
{
	//NF_UnloadTiledBg("bottom_splash");
	//NF_UnloadTiledBg("top_splash");
	////NF_DeleteTiledBg(0, 3);
	//NF_DeleteTiledBg(1, 3);
	NF_Unload16bitsBg(4);
	NF_Disble16bitsBackBuffer(4);
	//NF_ResetTiledBgBuffers();
	//NF_ResetSpriteBuffers();
}

void SplashScreen::update(float deltaTime)
{
	if (KEY_A & keysCurrent() || KEY_START & keysCurrent() || KEY_TOUCH & keysCurrent()) {
		changeState(new MainMenu(manager));
	}
	NF_Flip16bitsBackBuffer(0);
	NF_Flip16bitsBackBuffer(1);
}


void SplashScreen::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}
