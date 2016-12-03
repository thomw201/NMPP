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
	const char* createDataStr(int ballX, int ballY, int paddle1X, int paddle1Y, int paddle2X, int paddle2Y);
	int* receiveDataStr(std::string data);
private:
	char serverIP[18];
	bool connect();			// connect to wfc AP
	int paddle1X, paddle1Y, paddle2X, paddle2Y, ballX, ballY; //object locations to be received from server
};

