#include "PongHost.h"



PongHost::PongHost(StateManager &manager) : Pong(manager)
{
	controller.setMode(host);
	isP1 = true;
	if (!createServer()) //if creating server failed, return to main menu
	{
		changeState(new SplashScreen(manager));
	}
}


PongHost::~PongHost()
{
}

void PongHost::updateGame()
{
	controller.syncPaddleState(communication.listen());

	communication.send(controller.getGameState().c_str());
	//old host code
	//communication.send(communication.createDataStr(controller.getBallX(), controller.getBallY(), controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2), controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)));
	bal.setPosition(controller.getBallX(), controller.getBallY());
	p1Paddle.setPosition(controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2));
	p2Paddle.setPosition(controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)); 
}

//creates a server and waits for the client to connect
bool PongHost::createServer()
{
	consoleDemoInit();
	command = "";
	if (communication.createServer())
	{
		iprintf("\nServer started, waiting for client..\n\n"); // todo: add IP
															   //iprintf("\tServer IP:", inet_ntoa(NF_IP));
		command = communication.listen();
		while (command.compare("Start!") != 0) {
			if (KEY_SELECT & keysCurrent()) // user can return back to main menu by pressing select
			{
				//changestate
			}
			command = communication.listen();
		}
		communication.send("Go!");
		return true;
	}
	else {
		iprintf("\n\n\tFailed to create server.\n\n");
		return false;
	}
	return false;
}
