#include "UdpSocket.h"




UdpSocket::UdpSocket() 
{
}


UdpSocket::~UdpSocket()
{
}

void UdpSocket::socketDisconnect() {
	if (udp_socket >= 0)
	{
		closesocket(udp_socket);
		udp_socket = -1;
		free(SOC_buffer);
		SOC_buffer = NULL;
	}
}

void UdpSocket::printerror(const char *func, int err) {
	printf(errbuf, "  %s: err=%d", func, err);
	socketDisconnect();
	
}


int UdpSocket::activateSocket() {

	int ret;
	SOC_buffer = (u32*) memalign(SOC_ALIGN, SOC_BUFFERSIZE);

	if ((ret = socInit(SOC_buffer, SOC_BUFFERSIZE)) != 0) {
		free(SOC_buffer);
		SOC_buffer = NULL;
		return ret;
	}

	clientlen = sizeof(client);

	udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (udp_socket < 0)
	{
		return -1;
	}

	memset(&server, 0, sizeof(server));
	memset(&client, 0, sizeof(client));

	server.sin_family = AF_INET;
	server.sin_port = htons(TM_OWN_PORT);
	server.sin_addr.s_addr = gethostid();

	if (bind(udp_socket, (struct sockaddr*) &server, sizeof(server)) < 0) {
		return -1;
	}

	fcntl(udp_socket, F_SETFL, fcntl(udp_socket, F_GETFL, 0) | O_NONBLOCK);


	return 0;
}

int UdpSocket::sendString(string message) {
	//send the message to server
	if (sendto(udp_socket, message.c_str(), strlen(message.c_str()), 0, (struct sockaddr *)&client, sizeof(client)) != (int)strlen(message.c_str())) {
		return -1;
	}
	return 0;
}

int UdpSocket::getMessage(string &message) {
	//Receive the datagram back from server
	int addrLength(sizeof(client)), received(0);
	char buffer[1024] = { 0 };
	if ((received = recvfrom(udp_socket, buffer, 1024, 0, (sockaddr *)&client, (socklen_t*)&addrLength)) < 0) {
		return -1;
	}
	buffer[received] = '\0';
	printf(buffer);
	message = buffer;
	return 0;
}

string UdpSocket::getServerIp()
{
	return inet_ntoa(server.sin_addr);
}

int UdpSocket::getServerPort()
{
	return ntohs(server.sin_port);
}
/**
*
*/
string UdpSocket::getClientIp()
{
	return inet_ntoa(client.sin_addr);
}

int UdpSocket::getClientPort()
{
	return ntohs(client.sin_port);
}
