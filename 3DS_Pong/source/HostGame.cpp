#include "HostGame.h"

HostGame::HostGame(StateManager & manager) : GameState(manager)
{
	socket = new UdpSocket();
	socket->activateSocket();
	received = false;
	running = true;
}

HostGame::~HostGame()
{
	socket->socketDisconnect();
	delete socket;	
}

void HostGame::update(float deltaTime)
{

	held = hidKeysHeld();
	pressed = hidKeysDown();
	released = hidKeysUp();
	gspWaitForVBlank();
	if (received)
	{
		printf("Received message from ip: %s:%d\n", socket->getClientIp().c_str(),socket->getClientPort());
		printf("message reads: %s\n", message.c_str());
		received = false;
		socket->sendString("Thank you for your message, from: " + socket->getServerIp() + " ");
	}
	if (held & KEY_B)
	{
		changeState(new MultiPlayerMenu(manager));
	}
}

void HostGame::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void HostGame::getMessageLoop()
{
	while (running) {
		if (socket->getMessage(message) > -1)
		{
			received = true;
		}
	}

}
