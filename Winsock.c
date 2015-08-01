/*
 ============================================================================
 Name        : Winsock.c
 Author      : Yuval
 Version     :
 Copyright   : 
 Description : Server stuff in C11
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

/*
 * requires ws2_32.lib to be linked
 */

int main(int argc, char *argv[]) {

	WSADATA wsa;
	SOCKET s;
	char* IP = calloc(1, 255);
	int Port;
	struct sockaddr_in server;
	char* message, server_reply[2000];
	int recv_size;

	puts("\nInit...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	puts("Initialized\n");

	///Creating the socket

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Socket creation failure : ,%d", WSAGetLastError());
	}

	puts("Socket successfully created\n");

	puts("Please enter IP address: \n");

	gets(IP);

	puts("Enter Port:");

	scanf("%d", &Port);

	/*
	 * For Testing
	 * 173.194.112.111
	 * port 80
	 */

	server.sin_addr.s_addr = inet_addr(IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(Port);

	if (connect(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
		puts("Connection Error");
		return 1;
	}

	puts("Connected");

	///send Data
	message = "GET / HTTP/1.1\r\n\r\n";
	if (send(s, message, strlen(message), 0) < 0) {
		puts("Send Failed");
		return 1;
	}

	if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR) {
		puts("No reply received");
	}

	puts("Reply received");

	puts("Data successfully sent");

	server_reply[recv_size] = '\0';
	puts(server_reply);

	closesocket(s);
	WSACleanup();

	return 0;
}
