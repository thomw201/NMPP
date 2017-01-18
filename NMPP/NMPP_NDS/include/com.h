#include <nds.h>
#include "nf_wifi.h"
#include <string>
#include <vector>

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
	void receiveDataStr(std::string data);
	int clientObjectPositions[6];
	int getBallX();
	int getBallY();
	int getPaddle1X();
	int getPaddle1Y();
	int getPaddle2X();
	int getPaddle2Y();
private:
	char serverIP[18];
	bool connect();			// connect to wfc AP
};

