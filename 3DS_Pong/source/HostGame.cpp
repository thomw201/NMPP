#include "HostGame.h"

HostGame::HostGame(StateManager & manager, UdpSocket & socket) : GameState(manager), socket(socket)
{
	font = readBitmapFont((u8*)font_img.pixel_data, 32, 7, 16, 512);
	received = false;
	running = true;
	ip = socket.getServerIp() + ":";
	port = "13337";
	while (socket.getMessage(message) == 0) {}
	message = "No Message";
}

HostGame::~HostGame()
{
	sf2d_free_texture(font.bitmap);
}

void HostGame::update(float deltaTime)
{

	held = hidKeysHeld();
	pressed = hidKeysDown();
	released = hidKeysUp();
	//gspWaitForVBlank();
	if (socket.getMessage(message) == 0)
	{
		socket.sendString("I received: " + message + " from you!");
		if (message == "Start!") {
			socket.sendString("Go!");
			changeState(new HostPong(manager, socket));
		}
	}
	if (held & KEY_B)
	{
		changeState(new MainMenu(manager,socket));
	}



	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		renderBitmapText(ip, 0,0, font);
		renderBitmapText(port, 0, 40, font);
		renderBitmapText(message, 0, 80, font);
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		renderBitmapText(ip, 0, 0, font);
		renderBitmapText(port, 0, 40, font);
		renderBitmapText(message, 0, 80, font);
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		
	sf2d_end_frame();

	sf2d_swapbuffers();

}

void HostGame::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void HostGame::getMessageLoop()
{

}
