// Includes propietarios NDS
#include <nds.h>
#include "nf_wifi.h"
#include <string>

#pragma once
class com
{
public:
	com();
	~com();
	bool createClient(const char* IP);
	void send(const char* data);
	bool createServer();
	char* listen();
	bool isConnected;
private:
	char serverIP[18];
	bool connect();			// connect to wfc AP

	//u8 _SelectMode(void);				//server or client
	//s16 _SendData(const char* mydata);	// Send data over the open channel
	//s16 _GetData(void);					// receive data
	//s16 _LookForServer(void);
};

