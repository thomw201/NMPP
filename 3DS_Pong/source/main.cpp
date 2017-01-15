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

#include "GameState.h"
#include "SplashScreen.h"
#include "ClassicPong.h"
#include "UdpSocket.h"

//temp


chrono::time_point<chrono::steady_clock> start;

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
	sf2d_set_3D(1);

	u32 held;
	StateManager manager = StateManager();
	
	while (aptMainLoop()) {

		hidScanInput();
		held = hidKeysHeld();

		if (held & KEY_START) {
			break;
		}
		manager.update(frametimer());

	}

	sf2d_fini();

	return 0;
}
