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
	while(1) {

		swiWaitForVBlank();		// Espera al sincronismo vertical

	}

	return 0;

}
