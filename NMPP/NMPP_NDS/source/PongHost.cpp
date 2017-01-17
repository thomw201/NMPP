#include "PongHost.h"



PongHost::PongHost(StateManager &manager) : Pong(manager)
{
	controller.AIenabled = false;
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
	if (KEY_DOWN & keysCurrent()) {
		controller.movePaddle1(ponglogic::down);
	}
	else if (KEY_UP & keysCurrent()) {
		controller.movePaddle1(ponglogic::up);
	}
	else
		controller.movePaddle1(ponglogic::neutral);

	command = communication.listen();
	if (command.compare("up") == 0)
	{
		controller.movePaddle2(ponglogic::up);
	}
	else if (command.compare("down") == 0)
	{
		controller.movePaddle2(ponglogic::down);
	}
	else
		controller.movePaddle2(ponglogic::neutral);
	communication.send(communication.createDataStr(controller.getBallX(), controller.getBallY(), controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2), controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)));
	bal.setPosition(controller.getBallX(), controller.getBallY());
	p1Paddle.setPosition(controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2));
	p2Paddle.setPosition(controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)); //update game with local values as it's the host
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
		while (command.compare("handshake") != 0) {
			if (KEY_SELECT & keysCurrent()) // user can return back to main menu by pressing select
			{
				//changestate
			}
			command = communication.listen();
		}
		iprintf("Connected!");
		return true;
	}
	else {
		iprintf("\n\n\tFailed to create server.\n\n");
		return false;
	}
	return false;
}
