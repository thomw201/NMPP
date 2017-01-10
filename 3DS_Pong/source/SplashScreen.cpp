#include "SplashScreen.h"

SplashScreen::SplashScreen(GameState *currentState) : GameState(currentState)
{
	topScreen = sf2d_create_texture_mem_RGBA8(rainbowTop_img.pixel_data, rainbowTop_img.width, rainbowTop_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	botScreen = sf2d_create_texture_mem_RGBA8(rainbowTop_img.pixel_data, rainbowTop_img.width, rainbowTop_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
}

SplashScreen::~SplashScreen()
{
	delete topScreen;
	delete botScreen;
}

void SplashScreen::update(float deltaTime)
{
	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(topScreen, 0, 0);
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		sf2d_draw_texture(topScreen, 0, 0);
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_texture(botScreen, 0, 0);
	sf2d_end_frame();
}

void SplashScreen::changeState()
{
	//Todo:switch to the right gameState
}
