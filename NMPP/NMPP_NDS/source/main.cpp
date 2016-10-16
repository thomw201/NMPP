
#include <nf_lib.h>
#include <stdio.h>
#include "paddle.h"
#include "ball.h"
#include "GameController.h"
#include "GameObject.h"
#include <nds.h>
#include <chrono>



enum Screen{ Topscreen, Bottomscreen };
//const int bottomScreen = 1;
//const int topScreen = 0;

int gameScreen, menuScreen;
//paddle p1Paddle, p2Paddle; // paddle objects for player 1 & 2 - (in main method for now..)

chrono::time_point<chrono::steady_clock> start;

float frametimer()
{
	std::chrono::duration<float, milli> time = (chrono::steady_clock::now() - start);
	start = chrono::steady_clock::now();
	return time.count() / 1000;
}

void initBackgrounds() {
	// Initialize the Tiled Backgrounds System on the Top Screen
	NF_InitTiledBgBuffers();	// Initialize Background Buffers
	NF_InitTiledBgSys(gameScreen);		// Initialize Top and Bottom Screen BgSystems
	NF_InitTiledBgSys(menuScreen);
	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	NF_InitSpriteSys(gameScreen);		// Initialize Bottom Screen SpriteSystem

	NF_LoadTiledBg("splashImg", "TopBG", 256, 256); // splash background
	NF_LoadTiledBg("fieldImg", "BottomBG", 256, 256);	//field background

	NF_CreateTiledBg(menuScreen, 3, "TopBG");		// splash Background
	//NF_CreateTiledBg(gameScreen, 3, "BottomBG");		// game Background
}


/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {
	
	start = chrono::steady_clock::now();

	GameController game = GameController();

	// Set the Root Folder
	NF_SetRootFolder("NITROFS");
	gameScreen = Bottomscreen; // identify which screen should display the actual game
	menuScreen = Topscreen; // screen that will display the splash, menu, options etc

	NF_Set2D(gameScreen, 0);		//Set 2D MODE-0 to both Screens
	NF_Set2D(menuScreen, 0);

	initBackgrounds(); //initialize top and bottom screen backgrounds

	paddle p1Paddle = paddle(0, gameScreen, SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	paddle p2Paddle = paddle(1, gameScreen, SCREEN_WIDTH - SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);

	ball bal = ball(2, gameScreen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //init ball in the center of the screen
	bal.create();

	touchPosition Stylus;		// Prepare a variable for Stylus data

	p1Paddle.setSize(game.getPad1Width(), game.getPad1Length());
	p2Paddle.setSize(game.getPad2Width(), game.getPad2Length());


	p1Paddle.setPosition(game.getPad1X(), game.getPad1Y());// sync paddle positions
	p2Paddle.setPosition(game.getPad2X(), game.getPad1Y());
	p1Paddle.create(); //place the paddles
	p2Paddle.create();

	while(1) {

		scanKeys();		// Scan for Input
		touchRead(&Stylus);		// Read Stylus data

		//player 2 touch screen
		if (KEY_TOUCH & keysCurrent()) {
			
		}

		//player 1
		if (KEY_DOWN & keysCurrent()) {
				game.movePaddle1(down);
			//}
		}
		else if (KEY_UP & keysCurrent()) {
				game.movePaddle1(up);
		}
		else
			game.movePaddle1(neutral);

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

		bal.setPosition(game.getBallX(), game.getBallY());
		p1Paddle.setPosition(game.getPad1X()+ (game.getPad1Width()/2), game.getPad1Y() + (game.getPad1Length()/2));
		p2Paddle.setPosition(game.getPad2X()+ (game.getPad2Width()/2), game.getPad2Y() + (game.getPad2Length()/2));
		game.Update(0.05f);

		NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
		swiWaitForVBlank();		// Wait for the Vertical Blank
		oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	}

	return 0;

}
