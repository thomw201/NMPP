#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <fcntl.h>

#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <3ds.h>




class UdpSocket
{
private:

	#define SOC_ALIGN       0x1000
	#define SOC_BUFFERSIZE  0x100000
	#define TM_OWN_PORT 13337

	u32 *SOC_buffer = NULL;
	u32 clientlen;

	struct sockaddr_in client;
	struct sockaddr_in server;
	int udp_socket;
	char send_data[1024];
	char errbuf[1024];
	char *ip;
	const int port;
	

	void socketDisconnect();
	void printerror(const char *func, int err);
	

public:
	UdpSocket(char *ip, int port);
	~UdpSocket();
	int activateSocket();
	int sendString(char *message);
	int getMessage(char *message);
	


};

