
#include <nf_lib.h>
#include <stdio.h>
#include "paddle.h"
#include "ball.h"
#include "GameController.h"
#include "GameObject.h"
#include "com.h"
#include <nds.h>
#include <chrono>
#include <string>



//paddle p1Paddle, p2Paddle; // paddle objects for player 1 & 2 - (in main method for now..)

chrono::time_point<chrono::steady_clock> start;
enum gameMode { AI, Host, Client };

float frametimer()
{
	std::chrono::duration<float, milli> time = (chrono::steady_clock::now() - start);
	start = chrono::steady_clock::now();
	return time.count() / 1000;
}

void initBackgrounds() {
	// Initialize the Tiled Backgrounds System on the Top Screen
	NF_InitTiledBgBuffers();	// Initialize Background Buffers
	NF_InitTiledBgSys(0);
	NF_InitTiledBgSys(1);		// Initialize Top and Bottom Screen BgSystems

	NF_InitSpriteSys(1);		// Initialize Bottom Screen SpriteSystem

	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	NF_LoadTiledBg("splashImg", "TopBG", 256, 256); // splash background
	NF_LoadTiledBg("fieldImg", "BottomBG", 256, 256);	//field background

	NF_CreateTiledBg(0, 3, "TopBG");		// splash Background
	NF_CreateTiledBg(1, 3, "BottomBG");		// game Background
}

void keyPressed(int c) {
	if (c > 0) iprintf("%c", c);
}

//void vsAI(GameController game) { // maybe for future- make functions for gamemodes instead of going through if statements every single loop ..
//	while (true)
//	{
//
//	}
//}
//
//void vsHost(GameController game) {
//	while (true)
//	{
//
//	}
//}
//
//void vsClient(GameController game) {
//	while (true)
//	{
//
//	}
//}

/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {

	NF_Set2D(0, 0);
	NF_Set2D(1, 0);		//Set 2D MODE-0 to both Screens

	start = chrono::steady_clock::now();
	string command = ""; // buffer for commands from client
	GameController game = GameController();
	com com = com;
	com.isConnected = false;
	gameMode GameMode = AI; // default gamemode is p1 vs AI
	//init keyboard
	Keyboard* kb = keyboardDemoInit();
	kb->OnKeyPressed = keyPressed;
	// Set the Root Folder
	NF_SetRootFolder("NITROFS");
	consoleDemoInit();
	iprintf("\n\n\tNintendo Multi Platform Pong\n\n");
	iprintf("\n\n\t(A) - Player vs AI\n\t(B) - Player vs Player\n\n");
	while (!(keysCurrent() & KEY_A || keysCurrent() & KEY_B));
	if (KEY_B & keysCurrent())
	{
		game.AIenabled = false;
		//player vs player, decide if you want to be the server or client
		consoleClear();
		iprintf("\n\n\tNintendo Multi Platform Pong\n\n");
		iprintf("\n\n\t(X) - Host game\n\t(Y) - Connect to server\n\n");

		while (!(keysCurrent() & KEY_X || keysCurrent() & KEY_Y));
		if (KEY_X & keysCurrent())
		{
			if (com.createServer())
			{
				GameMode = Host;
				iprintf("\nServer started, waiting for client..\n\n"); // todo: add IP
				//iprintf("\tServer IP:", inet_ntoa(NF_IP));
				command = com.listen();
				while (command.compare("handshake") != 0) {
					command = com.listen();
				}
				iprintf("Connected!");
			}
			else
				iprintf("\n\n\tFailed to create server.\n\n");
		}
		else if (KEY_Y & keysCurrent())
		{
			GameMode = Client;
			char* IP = " ";
			char ipaddress[64];

			consoleClear();
			iprintf("\n\n\tEnter server IP:\n\n");
			while (IP == " ")
			{
				scanf("%s", ipaddress);
				IP = ipaddress;

			}
			if (com.createClient(IP))
			{
				iprintf("\n\n\Connected!\n\n");
				com.send("handshake");
			}
			else
				iprintf("\n\n\tFailed to connect to ", IP);
		}
	}
	else
		game.AIenabled = true;

	initBackgrounds(); //initialize top and bottom screen backgrounds

	paddle p1Paddle = paddle(0, 1, SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	paddle p2Paddle = paddle(1, 1, SCREEN_WIDTH - SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);

	ball bal = ball(2, 1, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //init ball in the center of the screen
	bal.create();

	touchPosition Stylus;		// Prepare a variable for Stylus data

	p1Paddle.setSize(game.getPad1Width(), game.getPad1Length());
	p2Paddle.setSize(game.getPad2Width(), game.getPad2Length());


	p1Paddle.setPosition(game.getPad1X(), game.getPad1Y());// sync paddle positions
	p2Paddle.setPosition(game.getPad2X(), game.getPad1Y());
	p1Paddle.create(); //place the paddles
	p2Paddle.create();

	while (1) {

		scanKeys();		// Scan for Input
		touchRead(&Stylus);		// Read Stylus data

		if (KEY_SELECT & keysCurrent()) { // DEBUG MODE
			consoleDemoInit(); // clear console
		}
		else if (KEY_R & keysCurrent())
		{

		}

		//player 1

		if (GameMode == AI || GameMode == Host) // if the gamemode is hosting or playing vs AI, enable control over paddle1 with up and down keys
		{
			if (KEY_DOWN & keysCurrent()) {
					game.movePaddle1(down);
			}
			else if (KEY_UP & keysCurrent()) {
					game.movePaddle1(up);
			}
			else
				game.movePaddle1(neutral);
			if (GameMode == Host) // if the gamemode is exclusively hosting, listen for movements from the client
			{
				command = com.listen();
				if (command.compare("up") == 0)
				{
					game.movePaddle2(up);
				}
				else if (command.compare("down") == 0)
				{
					game.movePaddle2(down);
				}
				else
					game.movePaddle2(neutral);
				//send game info to the client
				//string a = com.createDataStr(game.getBallX(), game.getBallY(), game.getPad1X() + (game.getPad1Width() / 2), game.getPad1Y() + (game.getPad1Length() / 2), game.getPad2X() + (game.getPad2Width() / 2), game.getPad2Y() + (game.getPad2Length() / 2));
				com.send(com.createDataStr(game.getBallX(), game.getBallY(), game.getPad1X() + (game.getPad1Width() / 2), game.getPad1Y() + (game.getPad1Length() / 2), game.getPad2X() + (game.getPad2Width() / 2), game.getPad2Y() + (game.getPad2Length() / 2)));
			}
			bal.setPosition(game.getBallX(), game.getBallY());
			p1Paddle.setPosition(game.getPad1X() + (game.getPad1Width() / 2), game.getPad1Y() + (game.getPad1Length() / 2));
			p2Paddle.setPosition(game.getPad2X() + (game.getPad2Width() / 2), game.getPad2Y() + (game.getPad2Length() / 2)); //update game with local values as it's the host
		}
		if (GameMode == Client) // if playing as client, send the movements to the server
		{
			command = com.listen();
			if (KEY_DOWN & keysCurrent()) {
				com.send("down");
			}
			else if (KEY_UP & keysCurrent()) {
				com.send("up");
			}
			if (command.compare("") != 0)
			{
				com.receiveDataStr(command);
				bal.setPosition(com.getBallX(), com.getBallY());
				p1Paddle.setPosition(com.getPaddle1X(), com.getPaddle1Y());
				p2Paddle.setPosition(com.getPaddle2X(), com.getPaddle2Y());
			}
		}
		////player 2 - X, B keys
		//if (KEY_B & keysCurrent()) {
		//	//if (p1Paddle.getY() < SCREEN_HEIGHT - SCREEN_HEIGHT*0.15)
		//	//{
		//		//p1Paddle.setY(p1Paddle.getY() + 5);
		//		game.movePaddle2(down);
		//	//}
		//}
		//else if (KEY_X & keysCurrent()) {
		//	if (p1Paddle.getY() > 0)
		//		//{
		//			//p1Paddle.setY(p1Paddle.getY() - 5);
		//		game.movePaddle2(up);
		//	//}
		//}
		//else
		//	game.movePaddle2(neutral);

		//bal.setPosition(game.getBallX(), game.getBallY());
		//p1Paddle.setPosition(game.getPad1X() + (game.getPad1Width() / 2), game.getPad1Y() + (game.getPad1Length() / 2));
		//p2Paddle.setPosition(game.getPad2X() + (game.getPad2Width() / 2), game.getPad2Y() + (game.getPad2Length() / 2));
		game.Update(0.05f);

		NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
		swiWaitForVBlank();		// Wait for the Vertical Blank
		oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	}

	return 0;

}
