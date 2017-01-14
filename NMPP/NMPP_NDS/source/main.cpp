
#include <nf_lib.h>
#include <stdio.h>
#include <nds.h>
#include <chrono>
#include <string>
#include "GameState.h"



//chrono::time_point<chrono::steady_clock> start;
//enum screen { Topscreen, Bottomscreen };
//
//
////float frametimer()
////{
////	std::chrono::duration<float, milli> time = (chrono::steady_clock::now() - start);
////	start = chrono::steady_clock::now();
////	return time.count() / 1000;
////}
//
//void initBackgrounds() {
//	// Initialize the Tiled Backgrounds System on the Top Screen
//	NF_InitTiledBgBuffers();	// Initialize Background Buffers
//	NF_InitTiledBgSys(Topscreen);
//	NF_InitTiledBgSys(Bottomscreen);		// Initialize Top and Bottom Screen BgSystems
//	
//	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
//	NF_InitSpriteSys(Topscreen);
//	NF_InitSpriteSys(Bottomscreen);		// Initialize Bottom Screen SpriteSystem
//
//	
//	NF_LoadTiledBg("splashImg", "TopBG", 256, 256); // splash background
//	NF_LoadTiledBg("fieldImg", "BottomBG", 256, 256);	//field background
//
//	NF_CreateTiledBg(Bottomscreen, 3, "TopBG");		// splash Background
//	NF_CreateTiledBg(Topscreen, 3, "BottomBG");		// game Background
//}

void keyPressed(int c) {
	if (c > 0) iprintf("%c", c);
}



/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {
	NF_Set2D(0, 0);
	NF_Set2D(1, 0);		//Set 2D MODE-0 to both Screens
	consoleDemoInit();
	swiWaitForVBlank();
	//start = chrono::steady_clock::now();
	//init keyboard
	Keyboard* kb = keyboardDemoInit();
	kb->OnKeyPressed = keyPressed;
	// Set the Root Folder
	NF_SetRootFolder("NITROFS");
	consoleDemoInit();
	
	StateManager manager = StateManager();
	

	touchPosition Stylus;		// Prepare a variable for Stylus data

	//initBackgrounds(); //initialize top and bottom screen backgrounds

	while (1) {
		if (KEY_START & keysCurrent())
		{
			break;
		}
		manager.update(0.05f);
	}

	return 0;

}
