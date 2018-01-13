#ifndef TCPCON_H
#define TCPCON_H

#include <iostream>
#include <winsock2.h>


class TCPCON {
public:
	TCPCON();
	~TCPCON();
	char* readPacket();
	void sendPacket(char* data);

	bool connectServer(int Port, char* IP);
	void closeSocket();
private:
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	char data[1024];
};

#endif