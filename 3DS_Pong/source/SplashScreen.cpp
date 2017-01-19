#include "SplashScreen.h"


SplashScreen::SplashScreen(StateManager & manager, UdpSocket &socket) : GameState(manager), socket(socket)
{
	topScreen = sf2d_create_texture_mem_RGBA8(splashScreen_img.pixel_data, splashScreen_img.width, splashScreen_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	botScreen = sf2d_create_texture_mem_RGBA8(pressStartScreen_img.pixel_data, pressStartScreen_img.width, pressStartScreen_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	srand(242435235);
}

SplashScreen::~SplashScreen()
{
	sf2d_free_texture(topScreen);
	sf2d_free_texture(botScreen);
}

void SplashScreen::update(float deltaTime)
{
	held = hidKeysHeld();

	if (held & KEY_A || held & KEY_START || hidKeysUp() & KEY_TOUCH) {
		changeState(new MainMenu(manager,socket));
	}
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(topScreen, 0, 0);
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		sf2d_draw_texture(topScreen, 0, 0);
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_texture(botScreen, 0, 0);
	sf2d_end_frame();


	sf2d_swapbuffers();
}


void SplashScreen::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}
