
#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <gmtl\gmtl.h>
#include <gmtl\Matrix.h>
#include "paddle.h"
#include "ball.h"

int gameScreen, menuScreen;
//paddle p1Paddle, p2Paddle; // paddle objects for player 1 & 2 - (in main method for now..)



void initBackgrounds() {
	// Initialize the Tiled Backgrounds System on the Top Screen
	NF_InitTiledBgBuffers();	// Initialize Background Buffers
	NF_InitTiledBgSys(0);		// Initialize Top and Bottom Screen BgSystems
	NF_InitTiledBgSys(1);
	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	NF_InitSpriteSys(1);		// Initialize Bottom Screen SpriteSystem

	NF_LoadTiledBg("splashImg", "Background", 256, 256); // splash background
	NF_LoadTiledBg("fieldImg", "Bottom", 256, 256);	//field background

	NF_CreateTiledBg(0, 3, "Background");		// Create the Top Background
	NF_CreateTiledBg(1, 3, "Bottom");		// Create the Bottom Background
}

/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {
	//int paddlePositionY = SCREEN_HEIGHT / 2;
	// Set the Root Folder
	NF_SetRootFolder("NITROFS");
	gameScreen = 1; // identify which screen should display the actual game
	menuScreen = 0; // screen that will display the splash, menu, options etc

	NF_Set2D(0, 0);		//Set 2D MODE-0 to both Screens
	NF_Set2D(1, 0);

	initBackgrounds(); //initialize top and bottom screen backgrounds

	paddle p1Paddle = paddle(0, gameScreen, SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	p1Paddle.create();

	paddle p2Paddle = paddle(1, gameScreen, SCREEN_WIDTH - SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	p2Paddle.create(); 

	ball bal = ball(2, gameScreen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //init ball in the center of the screen
	bal.create();


	touchPosition Stylus;		// Prepare a variable for Stylus data

	while(1) {

		scanKeys();		// Scan for Input
		touchRead(&Stylus);		// Read Stylus data

		//player 2 touch screen
		if (KEY_TOUCH & keysCurrent()) {
			if (Stylus.py > p2Paddle.getY())
			{
				p2Paddle.setY(p2Paddle.getY() + 5);
			}
			else if (Stylus.py < p2Paddle.getY())
			{
				p2Paddle.setY(p2Paddle.getY() - 5);
			}
		}

		//player 2
		if (KEY_DOWN & keysCurrent()) {
			if (p2Paddle.getY() < SCREEN_HEIGHT-SCREEN_HEIGHT*0.15)
			{
				p2Paddle.setY(p2Paddle.getY() + 5);
			}
		}
		if (KEY_UP & keysCurrent()) {
			if (p2Paddle.getY() > 0)
			{
				p2Paddle.setY(p2Paddle.getY() - 5);
			}
		}

		//player 1 - X, B keys
		if (KEY_B & keysCurrent()) {
			if (p1Paddle.getY() < SCREEN_HEIGHT - SCREEN_HEIGHT*0.15)
			{
				p1Paddle.setY(p1Paddle.getY() + 5);
			}
		}
		if (KEY_X & keysCurrent()) {
			if (p1Paddle.getY() > 0)
			{
				p1Paddle.setY(p1Paddle.getY() - 5);
			}
		}

		NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
		swiWaitForVBlank();		// Wait for the Vertical Blank
		oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	}

	return 0;

}
