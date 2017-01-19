#include "JoinGame.h"

JoinGame::JoinGame(StateManager & manager, UdpSocket & socket) : GameState(manager), socket(socket)
{
	font = readBitmapFont((u8*)font_img.pixel_data, 32, 7, 16, 512);
	ipset = false;
	portset = false;	
	ip = "";
	port = "";
	numbers = "0123456789.";
	count = 0;
	while (socket.getMessage(message) == 0) {}
	message = "No Message";
}

JoinGame::~JoinGame()
{
	sf2d_free_texture(font.bitmap);
}

void JoinGame::update(float deltaTime)
{
	held = hidKeysHeld();
	pressed = hidKeysDown();
	released = hidKeysUp();
	//gspWaitForVBlank();

	if (held & KEY_TOUCH) {
		hidTouchRead(&touch);		
	}
	if (socket.getMessage(message) == 0)
	{
		socket.sendString("I received: " + message + " from you!");
		if (message == "Go!") {
			changeState(new ClientPong(manager, socket));
		}
	}
	if (held & KEY_SELECT)
	{
		changeState(new MainMenu(manager, socket));
	}
	if (pressed & KEY_LEFT)
	{
		count--;
		if (count < 0)
		{
			count = numbers.size() - 1;
		}
	}
	if (pressed & KEY_RIGHT)
	{
		count++;
		if (count >= (int)numbers.size())
		{
			count = 0;
		}
	}
	if (pressed & KEY_X)
	{
		socket.setClientAdress(ip, atoi(port.c_str()));
		socket.sendString("Start!");
		message = "waiting";
	}
	if (pressed & KEY_R)
	{
		ipset = !ipset;
	}
	if (pressed & KEY_A)
	{
		if (!ipset)
		{
			ip += numbers.substr(count, 1);
		}
		else
		{
			port += numbers.substr(count, 1);
		}		
	}
	if (pressed & KEY_B)
	{
		if (!ipset)
		{
			if (ip.size() > 0)
			{
				ip = ip.substr(0, ip.size() - 1);
			}
		}
		else
		{
			if (port.size() > 0)
			{
				port = port.substr(0, port.size() - 1);
			}
		}
	}

	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		renderBitmapText(ip, 0,0, font);
		renderBitmapText(port, 0, 40, font);
		renderBitmapText(message, 0, 80, font);
		renderBitmapText("X: SUBMIT B:DEL", 0, 120, font);
		renderBitmapText("R: SWITCH A:PUT", 0, 160, font);
		renderBitmapText("<-,->:CHANGE NUM", 0, 200, font);
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		renderBitmapText(ip, 0, 0, font);
		renderBitmapText(port, 0, 40, font);
		renderBitmapText(message, 0, 80, font);
		renderBitmapText("X: SUBMIT B:DEL", 0, 120, font);
		renderBitmapText("R: SWITCH A:PUT", 0, 160, font);
		renderBitmapText("<-,->:CHANGE NUM", 0, 200, font);
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		renderBitmapText(numbers.substr(count,1), 140, 100, font);
	sf2d_end_frame();

	sf2d_swapbuffers();

}

void JoinGame::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

