#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <gmtl\gmtl.h>
#include <gmtl\Matrix.h>
#include <assert.h>
#include "Sprites.h"
#include "paddleImg.h"
#include "splashImg.h"


/* Select a low priority DMA channel to perform our background copying. */
static const int DMA_CHANNEL = 3;

/*
	Map VRAM to display a background on the main and sub screens.
*/
void initVideo() {
	vramSetMainBanks(VRAM_A_MAIN_BG_0x06000000,
		VRAM_B_MAIN_BG_0x06020000,
		VRAM_C_SUB_BG_0x06200000,
		VRAM_D_LCD);

	vramSetBankE(VRAM_E_MAIN_SPRITE);

	/*  Set the video mode on the main screen. */
	videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
		DISPLAY_BG2_ACTIVE | // Enable BG2 for display
		DISPLAY_BG3_ACTIVE | // Enable BG3 for display
		DISPLAY_SPR_ACTIVE | // Enable sprites for display
		DISPLAY_SPR_1D       // Enable 1D tiled sprites
		);

	/*  Set the video mode on the sub screen. */
	videoSetModeSub(MODE_5_2D | // Set the graphics mode to Mode 5
		DISPLAY_BG3_ACTIVE); // Enable BG3 for display
}

void initBackgrounds() {
	/*  Set up affine background 3 on main as a 16-bit color background. */
	REG_BG3CNT = BG_BMP16_256x256 |
		BG_BMP_BASE(0) | // The starting place in memory
		BG_PRIORITY(3); // A low priority

						/*  Set the affine transformation matrix for the main screen background 3
						*  to be the identity matrix.
						*/
	REG_BG3PA = 1 << 8;
	REG_BG3PB = 0;
	REG_BG3PC = 0;
	REG_BG3PD = 1 << 8;

	/*  Place main screen background 3 at the origin (upper left of the
	*  screen).
	*/
	REG_BG3X = 0;
	REG_BG3Y = 0;

	/*  Set up affine background 2 on main as a 16-bit color background. */
	REG_BG2CNT = BG_BMP16_128x128 |
		BG_BMP_BASE(8) | // The starting place in memory
		BG_PRIORITY(2);  // A higher priority

						 /*  Set the affine transformation matrix for the main screen background 3
						 *  to be the identity matrix.
						 */
	REG_BG2PA = 1 << 8;
	REG_BG2PB = 0;
	REG_BG2PC = 0;
	REG_BG2PD = 1 << 8;

	/*  Place main screen background 2 in an interesting place. */
	REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
	REG_BG2Y = -32 << 8;

	/*  Set up affine background 3 on the sub screen as a 16-bit color
	*  background.
	*/
	REG_BG3CNT_SUB = BG_BMP16_256x256 |
		BG_BMP_BASE(0) | // The starting place in memory
		BG_PRIORITY(3); // A low priority

						/*  Set the affine transformation matrix for the sub screen background 3
						*  to be the identity matrix.
						*/
	REG_BG3PA_SUB = 1 << 8;
	REG_BG3PB_SUB = 0;
	REG_BG3PC_SUB = 0;
	REG_BG3PD_SUB = 1 << 8;

	/*
	*  Place main screen background 3 at the origin (upper left of the screen)
	*/
	REG_BG3X_SUB = 0;
	REG_BG3Y_SUB = 0;
}


void displaySplash() {
	dmaCopyHalfWords(DMA_CHANNEL,
		splashImgBitmap, /* This variable is generated for us by
					  * grit. */
		(uint16 *)BG_BMP_RAM_SUB(0), /* Our address for sub
									 * background 3 */
		splashImgBitmapLen); /* This length (in bytes) is generated
						  * from grit. */
}

int main() {
	powerOn(POWER_ALL_2D); // Turn on the 2D graphics core.



	/*  Configure the VRAM and background control registers. */
	lcdMainOnBottom(); // Place the main screen on the bottom physical screen
	initVideo();
	initBackgrounds();
	//display the splash screen
	displaySplash();


	while(1) {

		swiWaitForVBlank();

	}

	return 0;

}
