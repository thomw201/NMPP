#include "PongClient.h"




PongClient::PongClient(StateManager &manager) : Pong(manager)
{
	controller.AIenabled = false;
	if (!connect()) //if connecting, return to main menu
	{
		//change state
	}
}

PongClient::~PongClient()
{
}

void PongClient::updateGame()
{
	command = communication.listen();
	if (KEY_DOWN & keysCurrent()) {
		communication.send("down");
	}
	else if (KEY_UP & keysCurrent()) {
		communication.send("up");
	}
	if (command.compare("") != 0)
	{
		communication.receiveDataStr(command);
		bal.setPosition(communication.getBallX(), communication.getBallY());
		p1Paddle.setPosition(communication.getPaddle1X(), communication.getPaddle1Y());
		p2Paddle.setPosition(communication.getPaddle2X(), communication.getPaddle2Y());
	}
}

bool PongClient::connect()
{
	string command = ""; // buffer for commands from client
	controller.AIenabled = false;
	char const *IP = " ";
	char ipaddress[64];

	consoleClear();
	iprintf("\n\n\tEnter server IP:\n\n");
	//while (IP == " ")
	while (strcmp(" ", IP) != 0)
	{
		scanf("%s", ipaddress);
		IP = ipaddress;

	}
	if (communication.createClient(IP))
	{
		iprintf("%c%cConnected!%c%c",'\n', '\n', '\n', '\n');
		communication.send("handshake");
		return true;
	}
	else
		iprintf("\n\n\tFailed to connect to %s", IP);
	return false;
}
