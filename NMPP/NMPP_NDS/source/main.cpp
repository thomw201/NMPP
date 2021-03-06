
#include <nf_lib.h>
#include <stdio.h>
#include <nds.h>
#include <chrono>
#include <string>
#include "GameState.h"
#include "sprites.h"
#include <time.h>

//the speed of the timer when using ClockDivider_1024
#define TIMER_SPEED (BUS_CLOCK/1024)
unsigned int ticks = 0;

typedef enum
{
	timerState_Stop,
	timerState_Pause,
	timerState_Running
}TimerStates;

float timer() {
	timerStop(0);
	float t = (float)ticks / TIMER_SPEED;
	ticks = 0;
	timerStart(0, ClockDivider_1024, 0, NULL);
	return t;
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

	NF_Set2D(0, 5);				// set bitmap mode
	NF_Set2D(1, 5);

	//consoleDemoInit();
	
	NF_InitBitmapBgSys(0, 1);
	NF_InitBitmapBgSys(1, 1);
	NF_Init16bitsBgBuffers();
	NF_Init16bitsBackBuffer(0);
	NF_Init16bitsBackBuffer(1);
	NF_Enable16bitsBackBuffer(0);
	NF_Enable16bitsBackBuffer(1);
	//// Initialize the Tiled Backgrounds System on the Top Screen
	//NF_InitTiledBgBuffers();	// Initialize Background Buffers
	//NF_InitTiledBgSys(0);
	//NF_InitTiledBgSys(1);		// Initialize Top and Bottom Screen BgSystems

	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	NF_InitSpriteSys(0);
	NF_InitSpriteSys(1);		// Initialize Bottom Screen SpriteSystem



	StateManager manager = StateManager();
	



	loadSprites();

	while (1) {
		ticks += timerElapsed(0);
		manager.update(timer());
	}

	return 0;

}
