
#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

/*
-------------------------------------------------
	Main()
-------------------------------------------------
*/

int main(int argc, char **argv) {

	consoleDemoInit();		
	consoleClear();			
	setBrightness(3, 0);	
	// Turn on MODE 0 on the Top Screen
	NF_Set2D(0, 0);

	// Set the Root Folder
	NF_SetRootFolder("NITROFS");

	// Initialize the Tiled Backgrounds System on the Top Screen
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(0);

	// Load the Tiled Background
	NF_LoadTiledBg("Background", "Background", 256, 256);
	NF_CreateTiledBg(0, 3, "Background");

	printf("\n Multiplatform Pong v0.0001");



	while(1) {

		swiWaitForVBlank();		// Espera al sincronismo vertical

	}

	return 0;

}
