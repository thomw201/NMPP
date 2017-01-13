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
			//if (com.createServer())
			//{
			//	GameMode = Host;
			//	iprintf("\nServer started, waiting for client..\n\n"); // todo: add IP
			//														   //iprintf("\tServer IP:", inet_ntoa(NF_IP));
			//	command = com.listen();
			//	while (command.compare("handshake") != 0) {
			//		command = com.listen();
			//	}
			//	iprintf("Connected!");
			//}
			//else
			//	iprintf("\n\n\tFailed to create server.\n\n");
		}
		else if (KEY_Y & keysCurrent())
		{
			return Client;
			//GameMode = Client;
			////char* IP = " ";
			////char ipaddress[64];

			////consoleClear();
			////iprintf("\n\n\tEnter server IP:\n\n");
			////while (IP == " ")
			////{
			////	scanf("%s", ipaddress);
			////	IP = ipaddress;

			////}
			////if (com.createClient(IP))
			////{
			////	iprintf("\n\n\Connected!\n\n");
			////	com.send("handshake");
			////}
			////else
			////	iprintf("\n\n\tFailed to connect to ", IP);
		}
	}
	else
		return AI;
		/*game.AIenabled = true;*/
	return 0;
}

void menu::createButton()
{
}
