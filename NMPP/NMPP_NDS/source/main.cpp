
#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>


// Create a Sprite data structure to hold important information
typedef struct {
	u8 ID, X, Y, Frame;
} Sprite_Data;

Sprite_Data Sprite[9];


/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {
	int paddlePositionY = SCREEN_HEIGHT / 2;

	NF_Set2D(0, 0);		//Set 2D MODE-0 to both Screens
	NF_Set2D(1, 0);


	// Set the Root Folder
	NF_SetRootFolder("NITROFS");

	// Initialize the Tiled Backgrounds System on the Top Screen
	NF_InitTiledBgBuffers();	// Initialize Background Buffers
	NF_InitTiledBgSys(0);		// Initialize Top and Bottom Screen BgSystems
	NF_InitTiledBgSys(1);
	w
	NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	NF_InitSpriteSys(1);		// Initialize Bottom Screen SpriteSystem

	NF_LoadTiledBg("splashImg", "Background", 256, 256); // splash background
	NF_LoadTiledBg("fieldImg", "Bottom", 256, 256);	//field background


	NF_CreateTiledBg(0, 3, "Background");		// Create the Top Background
	NF_CreateTiledBg(1, 3, "Bottom");		// Create the Bottom Background

	NF_LoadSpriteGfx("paddleImg", 0, 8, 32);	// load paddle sprite
	NF_LoadSpritePal("paddleImg", 0);

	NF_LoadSpriteGfx("ballImg", 1, 16, 16);	// load paddle sprite
	NF_LoadSpritePal("ballImg", 1);

	NF_VramSpriteGfx(1, 0, 0, true);	// Load the Gfx into VRAM - transfer all Sprites
	NF_VramSpritePal(1, 0, 0);		// Load the Palette into VRAM
	NF_VramSpriteGfx(1, 1, 1, true);	// Load the Gfx into VRAM - transfer all Sprites
	NF_VramSpritePal(1, 1, 1);		// Load the Palette into VRAM


	//place paddles at the left & right side
	NF_CreateSprite(1, 0, 0, 0, SCREEN_WIDTH*0.05, SCREEN_HEIGHT/2);		//create paddle 5% from the border and in the middle of the screen (vertically)
	NF_CreateSprite(1, 1, 0, 0, SCREEN_WIDTH - SCREEN_WIDTH*0.05, paddlePositionY);		//create paddle 5% from the border and in the middle of the screen (vertically)

	NF_CreateSprite(1, 2, 1, 1, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	//NF_SpriteFrame(1, 3, 0);		// Set its Frame to a blank one

	touchPosition Stylus;		// Prepare a variable for Stylus data

	while(1) {

		scanKeys();		// Scan for Input
		touchRead(&Stylus);		// Read Stylus data

		if (KEY_TOUCH & keysCurrent()) {
			if (Stylus.py > paddlePositionY)
			{
				NF_MoveSprite(1, 1, SCREEN_WIDTH - SCREEN_WIDTH*0.05, paddlePositionY += 1);
			}
			else if (Stylus.py < paddlePositionY)
			{
				NF_MoveSprite(1, 1, SCREEN_WIDTH - SCREEN_WIDTH*0.05, paddlePositionY -= 1);
			}
		}

		if (KEY_DOWN & keysCurrent()) {
			if (paddlePositionY < SCREEN_HEIGHT-SCREEN_HEIGHT*0.15)
			{
				NF_MoveSprite(1, 1, SCREEN_WIDTH - SCREEN_WIDTH*0.05, paddlePositionY += 5);
			}
		}
		if (KEY_UP & keysCurrent()) {
			if (paddlePositionY > 0)
			{
				NF_MoveSprite(1, 1, SCREEN_WIDTH - SCREEN_WIDTH*0.05, paddlePositionY -= 5);
			}
		}

		NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
		swiWaitForVBlank();		// Wait for the Vertical Blank
		oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	}

	return 0;

}
