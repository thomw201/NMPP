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

	//struct sockaddr_in serv_addr;
	// create udp socket
	udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (udp_socket < 0)
	{
		printerror("udp socket", errno);
		return -1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	if (bind(udp_socket, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printerror("bind udp socket", errno);
		return -1;
	}

	inet_pton(AF_INET, "192.168.0.10", &serv_addr.sin_addr.s_addr);



	return 0;
}

int UdpSocket::sendString(char *message) {
	//send the message to server
	if (sendto(udp_socket, message, strlen(message), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != (int)strlen(message)) {
		printerror("bytes missmatch", errno);
		return -1;
	}
	return 0;
}

int UdpSocket::getMessage(char *message) {
	//Receive the datagram back from server
	int addrLength(sizeof(serv_addr)), received(0);
	char buffer[256] = { 0 };
	if ((received = recvfrom(udp_socket, buffer, 256, 0, (sockaddr *)&serv_addr, (socklen_t*)&addrLength)) < 0) {
		printerror("bytes missmatch", errno);
		return -1;
	}
	buffer[received] = '\0';
	printf(buffer);
	//std::cout << "Server (" << inet_ntoa(myaddr.sin_addr) << ") echoed: " << buffer << std::endl;
	message = buffer;
	return 0;
}