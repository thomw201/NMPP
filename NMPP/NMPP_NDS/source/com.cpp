#include "com.h"
#include <nds.h>

#include <stdio.h>
#include <string.h>

#include <nf_lib.h>
#include "nf_wifi.h"
#include <string>

#define port 1234

com::com()
{
	isConnected = false;
}


com::~com()
{
}

bool com::createClient(const char * IP)
{
	//consoleDemoInit();
	if (isConnected)
	{
		return NF_WIFI_CreateUdpSender(IP, port);
	}
	else if (connect())
	{
		return NF_WIFI_CreateUdpSender(IP, port);
	}
	else
		iprintf("Cannot create listener.");
	return false;
}



void com::send(const char* data)
{
	if (isConnected)
	{
		NF_WIFI_UdpSend(data);
	}
}

bool com::createServer()
{
	//consoleDemoInit();
	if (isConnected)
	{
		return NF_WIFI_CreateUdpListener(port);
	}
	else if (connect())
	{
		return NF_WIFI_CreateUdpListener(port);
	}
	else
		iprintf("Cannot create server.");
	return false;
}

char* com::listen()
{
	NF_BYTES_RECIEVED = 0;
	memset(NF_RECV_BUFFER, 0, sizeof NF_RECV_BUFFER); // CLEAR BUFFER
	NF_WIFI_UdpListen(100);
if (NF_BYTES_RECIEVED > 0)
{
	return NF_RECV_BUFFER;
}
else
return "";
}



bool com::connect()
{
	//consoleDemoInit();
	iprintf("Connecting to WFC AP...\n\n");


	//swiWaitForVBlank();
	if (NF_WiFiConnectDefaultAp()) {

		iprintf("Connected!\n\n");
		iprintf("Ip     : %s\n", inet_ntoa(NF_IP));
		iprintf("Gateway: %s\n", inet_ntoa(NF_GATEWAY));
		iprintf("Mask   : %s\n", inet_ntoa(NF_MASK));
		iprintf("Dns1   : %s\n", inet_ntoa(NF_DNS1));
		iprintf("Dns2   : %s\n\n", inet_ntoa(NF_DNS2));

		isConnected = true;

	}
	else {
		iprintf("Connection failed.\n");
	}

	swiWaitForVBlank();
	return isConnected;
}


