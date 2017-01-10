#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <math.h>
#include <3ds.h>
#include <sf2d.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <3ds/services/soc.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#include "citra_img.c"
#include "dice_img.c"
#include "GameController.h"
#include "GameState.h"
#include "SplashScreen.h"
#include "UdpSocket.h"

//temp


chrono::time_point<chrono::steady_clock> start;
Result ret;
u32 *ptr;

float frametimer()
{
	std::chrono::duration<float, milli> time = (chrono::steady_clock::now() - start);
	start = chrono::steady_clock::now();
	return time.count() / 1000;
}

#define CONFIG_3D_SLIDERSTATE (*(float *)0x1FF81080)

int main()
{
	//Code for frameTimer
	start = chrono::steady_clock::now();

	//Code to Initiliaze 2d library
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
	sf2d_set_3D(0);

	float offset3d = 0.0f;
	float rad = 0.0f;
	u16 touch_x = 320/2;
	u16 touch_y = 240/2;
	touchPosition touch;
	circlePosition circle;
	u32 held;
	GameState *currentState = new SplashScreen(currentState);
	
	while (aptMainLoop()) {

		hidScanInput();
		hidCircleRead(&circle);
		held = hidKeysHeld();

		if (held & KEY_START)
			break;



		currentState->update(frametimer());
	
		sf2d_swapbuffers();

	}

	sf2d_fini();
	return 0;
}
