// #include "../headers/tcpcon.h"

// TCPCON::TCPCON() {
// 	WSAStartup(MAKEWORD(2, 0), &WSAData);
// 	server = socket(AF_INET, SOCK_STREAM, 0);
// }

// TCPCON::~TCPCON() {
// 	closeSocket();
// }

// char*
// TCPCON::readPacket() {
// 	memset(data, 0, sizeof(data)); // clear data
// 	recv(server, data, sizeof(data), 0);
// 	return data;
// }

// void 
// TCPCON::sendPacket(char* data) {
// 	send(server, data, sizeof(data), 0);
// }

// bool TCPCON::connectServer(int Port, char* IP) {
// 	addr.sin_addr.s_addr = inet_addr(IP);
// 	addr.sin_family = AF_INET;
// 	addr.sin_port = htons(Port);

// 	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
// 	if (s == INVALID_SOCKET) {
// 		return false;
// 	}

// 	if (connect(s, (SOCKADDR *)&addr, sizeof(addr)) == SOCKET_ERROR) {
// 		return false;
// 	}
// 	else {
// 		std::cout << "Connected to server!" << std::endl;
// 		return true;
// 	}
// }

// void 
// TCPCON::closeSocket() {
// 	closesocket(server);
// 	WSACleanup();
// 	std::cout << "Socket closed." << std::endl << std::endl;
// }