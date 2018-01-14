// #ifndef TCPCON_H
// #define TCPCON_H
// #include <iostream>
// #ifdef defined(_WIN32) || defined(WIN32)
// #include <winsock2.h>
// #elif __unix__ 
// #include <stdio.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <netinet/in.h>
// #include <string.h>
// #endif
// #ifdef defined(_WIN32) || defined(WIN32)

// class TCPCON {
// public:
// 	TCPCON();
// 	~TCPCON();
// 	char* readPacket();
// 	void sendPacket(char* data);

// 	bool connectServer(int Port, char* IP);
// 	void closeSocket();
// private:
// 	WSADATA WSAData;
// 	SOCKET server;
// 	SOCKADDR_IN addr;

// 	char data[1024];
// };

// #elif __unix__ 


// class TCPCON {
// public:
// 	TCPCON();
// 	~TCPCON();
// 	char* readPacket();
// 	void sendPacket(char* data);

// 	bool connectServer(int Port, char* IP);
// 	void closeSocket();
// private:
// 	SOCKET server;
// 	SOCKADDR_IN addr;

// 	char data[1024];
// };
// #endif


// #endif