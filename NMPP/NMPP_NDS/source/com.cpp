#include "com.h"
#include <nds.h>

#include <stdio.h>
#include <string.h>

#include <nf_lib.h>
#include "nf_wifi.h"
#include <string>
#include <sstream>
#include <vector>

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
		iprintf("Failed to create client.");
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
	NF_WIFI_UdpListen(10); // was 50
	if (NF_BYTES_RECIEVED > 0)
	{
		return NF_RECV_BUFFER;
	}
	else
		return " ";
}

const char* com::createDataStr(int ballX, int ballY, int paddle1X, int paddle1Y, int paddle2X, int paddle2Y)
{
	std::string result = "object locations: ,";
	std::string value = "";

	value = static_cast<std::ostringstream*>(&(std::ostringstream() << ballX))->str() + ",";
	result.append(value);
	value = static_cast<std::ostringstream*>(&(std::ostringstream() << ballY))->str() + ",";
	result.append(value);
	value = static_cast<std::ostringstream*>(&(std::ostringstream() << paddle1X))->str() + ",";
	result.append(value);
	value = static_cast<std::ostringstream*>(&(std::ostringstream() << paddle1Y))->str() + ",";
	result.append(value);
	value = static_cast<std::ostringstream*>(&(std::ostringstream() << paddle2X))->str() + ",";
	result.append(value);
	value = static_cast<std::ostringstream*>(&(std::ostringstream() << paddle2Y))->str() + ",";
	result.append(value);

	return result.c_str();
}
void com::receiveDataStr(std::string data)
{
	//int objectPositions[7];
	//int index;
	//int convertToIntResult;
	//std::string position;
	//for (int j = 0; j < 7; j++)
	//{
	//	while (index < data.length())
	//	{
	//		if (data[0] == ',')
	//		{
	//			index++;
	//			break;
	//		}
	//		position += data[index];
	//		index++;
	//	}
	//	std::istringstream convert(position);
	//	if (!(convert >> convertToIntResult)) //give the value to 'Result' using the characters in the stream
	//		convertToIntResult = 0;
	//	objectPositions[j] = convertToIntResult;
	//	convert.clear();
	//}
	//return objectPositions;
	char delim = ',';
	int convertToIntResult;
	int countObjectPosition = 0;

	//if (!flds.empty()) flds.clear();  // empty vector if necessary
	std::string buf = "";
	unsigned int i = 0;
	while (data[i] != ',') // skip whatever is infront of the int coords
	{
		i++;
	}
	while (i < data.length()) {
		if (data[i] != delim)
			buf += data[i];
		//else if (rep == 1) {
		//	flds.push_back(buf);
		//	buf = "";
		else if (buf.length() > 0) {
			std::istringstream convert(buf);
			if (!(convert >> convertToIntResult)) { //give the value to 'Result' using the characters in the stream
				convertToIntResult = 0;
			}
				clientObjectPositions[countObjectPosition] = convertToIntResult;
				countObjectPosition++;
				convert.clear();
				buf = "";
			
		}
		i++;
	}
	if (!buf.empty()) {}
		//flds.push_back(0);
}

int com::getBallX()
{
	return clientObjectPositions[0];
}

int com::getBallY()
{
	return clientObjectPositions[1];
}

int com::getPaddle1X()
{
	return clientObjectPositions[2];
}

int com::getPaddle1Y()
{
	return clientObjectPositions[3];
}

int com::getPaddle2X()
{
	return clientObjectPositions[4];
}


int com::getPaddle2Y()
{
	return clientObjectPositions[5];
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


