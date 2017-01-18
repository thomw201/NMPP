#include "MultiPlayerMenu.h"

MultiPlayerMenu::MultiPlayerMenu(StateManager & manager) : GameState(manager)
{
	//topScreen = sf2d_create_texture_mem_RGBA8(splashScreen_img.pixel_data, splashScreen_img.width, splashScreen_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	//buttons.push_back(new Button(10, 10, joinFriendButton_img.pixel_data, joinFriendButtonSelected_img.pixel_data, joinFriendButton_img.width, joinFriendButton_img.height, 
	//	[]() {}));

	//buttons.push_back(new Button(10, 90, hostButton_img.pixel_data, hostButtonSelected_img.pixel_data, hostButton_img.width, hostButton_img.height,
	//	[&manager]() {manager.changeState(new HostGame(manager)); }));
	//buttons.push_back(new Button(10, 170, backButton_img.pixel_data, backButtonSelected_img.pixel_data, backButton_img.width, backButton_img.height,
	//	[&manager]() { manager.changeState(new SplashScreen(manager)); }));

	//buttonManager = new ButtonManager(buttons);
	
}

MultiPlayerMenu::~MultiPlayerMenu()
{
	sf2d_free_texture(topScreen);
	for (auto &button : buttons)
	{
		delete button;
	}
	buttons.clear();
	delete buttonManager;
}

void MultiPlayerMenu::update(float deltaTime)
{

	held = hidKeysHeld();
	pressed = hidKeysDown();
	released = hidKeysUp();

	if (released & KEY_TOUCH)
	{
		buttonManager->accept();
	}

	if (held & KEY_TOUCH) {
		hidTouchRead(&touch);
		buttonManager->touch(touch.px, touch.py);
	}

	if (pressed & KEY_UP)
	{
		buttonManager->up();
	}
	else if (pressed & KEY_DOWN)
	{
		buttonManager->down();
		
	}
	if (pressed & KEY_A) {
		buttonManager->accept();
	}
	if (pressed & KEY_B)
	{
		//changeState(new SplashScreen(manager));
	}

	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(topScreen, 0, 0);
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		sf2d_draw_texture(topScreen, 0, 0);
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		buttonManager->draw();
	sf2d_end_frame();

	sf2d_swapbuffers();
}

void MultiPlayerMenu::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}
