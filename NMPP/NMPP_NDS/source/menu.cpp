#include <nf_lib.h>
#include "menu.h"

enum gameMode { mainMenu, AI, Host, Client };

menu::menu()
{
}

menu::menu(int screen)
{
	//GameMode = AI; // default gamemode is p1 vs AI
}


menu::~menu()
{
}

int menu::run()
{
	iprintf("\n\n\tNintendo Multi Platform Pong\n\n");
	iprintf("\n\n\t(A) - Player vs AI\n\t(B) - Player vs Player\n\n");
	while (!(keysCurrent() & KEY_A || keysCurrent() & KEY_B));
	if (KEY_B & keysCurrent())
	{
		//game.AIenabled = false;
		//player vs player, decide if you want to be the server or client
		consoleClear();
		iprintf("\n\n\tNintendo Multi Platform Pong\n\n");
		iprintf("\n\n\t(X) - Host game\n\t(Y) - Connect to server\n\n");

		while (!(keysCurrent() & KEY_X || keysCurrent() & KEY_Y));
		if (KEY_X & keysCurrent())
		{
			return Host;

		}
		else if (KEY_Y & keysCurrent())
		{
			return Client;
		}
	}
	else
		return AI;
		/*game.AIenabled = true;*/
	return mainMenu;
}

void menu::createButton()
{
}
