#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <string.h>


class UdpSocket
{
private:
	struct sockaddr_in serv_addr;
	int udp_socket;
	char errbuf[1024];
	char *ip;
	const int port;
	

	void socketDisconnect();
	void printerror(const char *func, int err);
	//static int set_socket_nonblocking(int sock);
	

public:
	UdpSocket(char *ip, int port);
	~UdpSocket();
	int activateSocket();
	int sendString(char *message);
	int getMessage(char *message);
	


};

