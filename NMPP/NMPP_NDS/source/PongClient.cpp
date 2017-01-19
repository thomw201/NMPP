#include "PongClient.h"




PongClient::PongClient(StateManager &manager) : Pong(manager)
{
	controller.setMode(client);
	isP1 = false;
	if (!connect()) //if connecting, return to main menu
	{
		changeState(new SplashScreen(manager));
	}
}

PongClient::~PongClient()
{
}

void PongClient::updateGame()
{
	controller.syncGameState(communication.listen());
	if (KEY_DOWN & keysCurrent()) {
		controller.movePaddle2(down);
	}
	else if (KEY_UP & keysCurrent()) {
		controller.movePaddle2(up);
	}
	else if (KEY_SELECT & keysDown())
	{
		changeState(new SplashScreen(manager));
	}
	else
		controller.movePaddle2(neutral);
	communication.send(controller.getp2State().c_str());

	bal.setPosition(controller.getBallX(), controller.getBallY());
	p1Paddle.setPosition(controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2));
	p2Paddle.setPosition(controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2));

	//command = communication.listen();

	//if (KEY_DOWN & keysCurrent()) {
	//	communication.send("down");
	//}
	//else if (KEY_UP & keysCurrent()) {
	//	communication.send("up");
	//}
	////if (command.compare("") != 0)
	////{
	////	communication.receiveDataStr(command);
	////	bal.setPosition(communication.getBallX(), communication.getBallY());
	////	p1Paddle.setPosition(communication.getPaddle1X(), communication.getPaddle1Y());
	////	p2Paddle.setPosition(communication.getPaddle2X(), communication.getPaddle2Y());
	////}
}

bool PongClient::connect()
{
	consoleDemoInit();
	string command = ""; // buffer for commands from client
	char const *IP = " ";
	char ipaddress[64];

	consoleClear();
	iprintf("\n\n\tEnter server IP:\n\n");
	keyboardDemoInit();

	keyboardShow();
	while (IP == " ")
		//while (strcmp(" ", IP) != 0)
	{
		scanf("%s", ipaddress);
		IP = ipaddress;

	}
	if (communication.createClient(IP))
	{
		communication.send("Start!");
		//command = communication.listen();
		//while (command.compare("Go!") != 0) { //wait for server to reply

		//}
		return true;
	}
	else
		iprintf("\n\n\tFailed to connect to %s", IP);
	return false;
}
