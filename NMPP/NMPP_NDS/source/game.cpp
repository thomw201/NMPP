#include "game.h"
#include "GameController.h"
#include <nf_lib.h>
#include <stdio.h>
#include <string>
#include "paddle.h"
#include "ball.h"


game::game()
{
}

game::game(int screen)
{
	controller = ponglogic::GameController();
	communication.isConnected = false;
	p1Paddle = paddle(0, screen, SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	p2Paddle = paddle(1, screen, SCREEN_WIDTH - SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	bal = ball(2, screen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //init ball in the center of the screen
	bal.create();

	p1Paddle.setSize(controller.getPad1Width(), controller.getPad1Length());
	p2Paddle.setSize(controller.getPad2Width(), controller.getPad2Length());


	p1Paddle.setPosition(controller.getPad1X(), controller.getPad1Y());// sync paddle positions
	p2Paddle.setPosition(controller.getPad2X(), controller.getPad1Y());
	p1Paddle.create(); //place the paddles
	p2Paddle.create();
}


game::~game()
{
}

void game::run(int gamemode)
{
	switch (gamemode)
	{
	case 1:
		break;
	default:
		break;
	}
}

void game::vsAI()
{
	controller.AIenabled = true;
	while (1)
	{
		controlP1();
		bal.setPosition(controller.getBallX(), controller.getBallY());
		p1Paddle.setPosition(controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2));
		p2Paddle.setPosition(controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)); //update game with local values as it's the host
		update();
	}
}

//system is hosting the game - listen to local key input & listen to the client & send coordinates to the client
void game::isHost()
{
	string command = "";
	controller.AIenabled = false;
	if (communication.createServer())
	{
		iprintf("\nServer started, waiting for client..\n\n"); // todo: add IP
															   //iprintf("\tServer IP:", inet_ntoa(NF_IP));
		command = communication.listen();
		while (command.compare("handshake") != 0) {
			command = communication.listen();
		}
		iprintf("Connected!");
	}
	else {
		iprintf("\n\n\tFailed to create server.\n\n");
		if (KEY_START & keysCurrent())
		{
			return; // back to main menu
		}
	}
	while (1) //everything is set up, start game
	{
		controlP1();
		command = communication.listen();
		if (command.compare("up") == 0)
		{
			controller.movePaddle2(up);
		}
		else if (command.compare("down") == 0)
		{
			controller.movePaddle2(down);
		}
		else
			controller.movePaddle2(neutral);
		communication.send(communication.createDataStr(controller.getBallX(), controller.getBallY(), controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2), controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)));
		update();
	}
}

void game::isClient()
{
	string command = ""; // buffer for commands from client
	controller.AIenabled = false;
	char* IP = " ";
	char ipaddress[64];

	consoleClear();
	iprintf("\n\n\tEnter server IP:\n\n");
	while (IP == " ")
	{
		scanf("%s", ipaddress);
		IP = ipaddress;

	}
	if (communication.createClient(IP))
	{
		iprintf("\n\n\Connected!\n\n");
		communication.send("handshake");
	}
	else {
		iprintf("\n\n\tFailed to connect to ", IP);
		if (KEY_START & keysCurrent())
		{
			return; // back to main menu
		}
	}
	while (1)
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
		update();
	}
}

void game::show()
{

}

void game::hide()
{
}

void game::controlP1()
{
	if (KEY_DOWN & keysCurrent()) {
		controller.movePaddle1(down);
	}
	else if (KEY_UP & keysCurrent()) {
		controller.movePaddle1(up);
	}
	else
		controller.movePaddle1(neutral);
}

void game::update()
{
	controller.Update(0.05f); //update controller
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
	touchRead(&Stylus);		// Read Stylus data
}