#include "com.h"
#include <nds.h>

#include <stdio.h>
#include <string.h>

#include <nf_lib.h>
#include "nf_wifi.h"
#include <string>
#include <sstream>

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
		iprintf("Cannot create client.");
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
	NF_WIFI_UdpListen(50);
if (NF_BYTES_RECIEVED > 0)
{
	return NF_RECV_BUFFER;
}
else
return "";
}

const char* com::createDataStr(int ballX, int ballY, int paddle1X, int paddle1Y, int paddle2X, int paddle2Y)
{
	std::string result = "";
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
	//convert << ballY;
	//result.append(convert.str() + ",");
	//convert.clear();
	//convert << paddle1X;
	//result.append(convert.str() + ",");
	//convert.clear();
	//convert << paddle1Y;
	//result.append(convert.str() + ",");
	//convert.clear();
	//convert << paddle2X;
	//result.append(convert.str() + ",");
	//convert.clear();
	//convert << paddle2Y;
	//result.append(convert.str() + ",");
	//convert.clear();
	return result.c_str();
}

int * com::receiveDataStr(std::string data)
{
	int objectPositions[6];
	int index;
	int convertToIntResult;
	std::string position;
	for (int j = 0; j < 6; j++)
	{
		while (index < data.length())
		{
			if (data[0] == ',')
			{
				break;
			}
			position += data[index];
			index++;
		}
		std::istringstream convert(position);
		if (!(convert >> convertToIntResult)) //give the value to 'Result' using the characters in the stream
			convertToIntResult = 0;
		objectPositions[j] = convertToIntResult;
		convert.clear();
	}
	return objectPositions;
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


