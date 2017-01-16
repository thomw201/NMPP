#include "UdpSocket.h"




UdpSocket::UdpSocket(char *ip, int port) : ip(ip), port(port)
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

	return 0;
}

int UdpSocket::sendString(char *message) {
	//send the message to server
	if (sendto(udp_socket, message, strlen(message), 0, (struct sockaddr *)&server, sizeof(server)) != (int)strlen(message)) {
		return -1;
	}
	return 0;
}

int UdpSocket::getMessage(char *message) {
	//Receive the datagram back from server
	int addrLength(sizeof(client)), received(0);
	char buffer[256] = { 0 };
	if ((received = recvfrom(udp_socket, buffer, 256, 0, (sockaddr *)&client, (socklen_t*)&addrLength)) < 0) {
		return -1;
	}
	buffer[received] = '\0';
	printf(buffer);
	//std::cout << "Server (" << inet_ntoa(myaddr.sin_addr) << ") echoed: " << buffer << std::endl;
	message = buffer;
	return 0;
}