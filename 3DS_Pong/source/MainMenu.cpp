#include "MainMenu.h"


MainMenu::MainMenu(StateManager & manager, UdpSocket & socket) : GameState(manager), socket(socket)
{
	topScreen = sf2d_create_texture_mem_RGBA8(splashScreen_img.pixel_data, splashScreen_img.width, splashScreen_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	buttons.push_back(new Button(10, 10, singlePlayerButton_img.pixel_data, singlePlayerButtonSelected_img.pixel_data, singlePlayerButton_img.width, singlePlayerButton_img.height,
		[&]() { manager.changeState(new ClassicPong(manager, socket)); }));

	buttons.push_back(new Button(10, 90, joinFriendButton_img.pixel_data, joinFriendButtonSelected_img.pixel_data, singlePlayerButton_img.width, singlePlayerButton_img.height,
		[&]() { manager.changeState(new JoinGame(manager, socket)); }));
	buttons.push_back(new Button(10, 170, hostButton_img.pixel_data, hostButtonSelected_img.pixel_data, singlePlayerButton_img.width, singlePlayerButton_img.height,
		[&]() { manager.changeState(new HostGame(manager, socket)); }));

	buttonManager = new ButtonManager(buttons);
}

MainMenu::~MainMenu()
{
	sf2d_free_texture(topScreen);
	for (auto &button : buttons)
	{
		delete button;
	}
	buttons.clear();
	delete buttonManager;
}

void MainMenu::update(float deltaTime)
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
		changeState(new SplashScreen(manager,socket));
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

void MainMenu::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}
