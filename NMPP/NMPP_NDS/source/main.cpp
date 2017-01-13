
#include <nf_lib.h>
#include <stdio.h>
#include "game.h"
#include "menu.h"

#include "com.h"
#include <nds.h>
#include <chrono>
#include <string>



//paddle p1Paddle, p2Paddle; // paddle objects for player 1 & 2 - (in main method for now..)

chrono::time_point<chrono::steady_clock> start;
enum screen { Topscreen, Bottomscreen };
enum gameMode { mainMenu, AI, Host, Client };

float frametimer()
{
	std::chrono::duration<float, milli> time = (chrono::steady_clock::now() - start);
	start = chrono::steady_clock::now();
	return time.count() / 1000;
}

void initBackgrounds() {
	// Initialize the Tiled Backgrounds System on the Top Screen
	NF_InitTiledBgBuffers();	// Initialize Background Buffers
	NF_InitTiledBgSys(Topscreen);
	NF_InitTiledBgSys(Bottomscreen);		// Initialize Top and Bottom Screen BgSystems
	
	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	NF_InitSpriteSys(Topscreen);
	NF_InitSpriteSys(Bottomscreen);		// Initialize Bottom Screen SpriteSystem

	
	NF_LoadTiledBg("splashImg", "TopBG", 256, 256); // splash background
	NF_LoadTiledBg("fieldImg", "BottomBG", 256, 256);	//field background

	NF_CreateTiledBg(Bottomscreen, 3, "TopBG");		// splash Background
	NF_CreateTiledBg(Topscreen, 3, "BottomBG");		// game Background
}

void keyPressed(int c) {
	if (c > 0) iprintf("%c", c);
}



/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {

	game Game = game(Topscreen); //init game on top screen
	menu Menu = menu(Bottomscreen); //init menu on bottom screen
	gameMode gamemode = mainMenu;
	NF_Set2D(Topscreen, 0);
	NF_Set2D(Bottomscreen, 0);		//Set 2D MODE-0 to both Screens
	consoleDemoInit();
	swiWaitForVBlank();
	start = chrono::steady_clock::now();
	//init keyboard
	Keyboard* kb = keyboardDemoInit();
	kb->OnKeyPressed = keyPressed;
	// Set the Root Folder
	NF_SetRootFolder("NITROFS");
	consoleDemoInit();
	
	

	touchPosition Stylus;		// Prepare a variable for Stylus data

	initBackgrounds(); //initialize top and bottom screen backgrounds

	while (1) {
		switch (gamemode)
		{
		case mainMenu:
			Menu.run();
			break;
		case AI:
			Game.vsAI();
			break;
		case Host:
			Game.isHost();
			break;
		case Client:
			Game.isClient();
			break;
		default:
			break;
		}
		gamemode = mainMenu; // when exitted out of a gamestate, go back to main menu
	}

	return 0;

}
