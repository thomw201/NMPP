#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <gmtl\gmtl.h>
#include <gmtl\Matrix.h>
#include <GameObject.h>



/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {
<<<<<<< HEAD
	powerOn(POWER_ALL_2D); // Turn on the 2D graphics core.
	lcdMainOnBottom();
	//initVideo();
	//initBackgrounds();
	///* Set up a few sprites. */
	//SpriteInfo spriteInfo[SPRITE_COUNT];
	
	GameObject gameobj();

	OAMTable *oam = new OAMTable();
	gmtl::Matrix44f test_matrix;
	test_matrix.set(new float(1.0f));
=======
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

>>>>>>> feature/Nightfoxlib_sprites
	while(1) {

		swiWaitForVBlank();		// Espera al sincronismo vertical

	}

	return 0;

}
