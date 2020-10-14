#include <iostream>
#include <string>
#include <WinSock2.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")
const int BUFF_SIZE = 1024;
#define PORT 8086

int main()
{
	//init WSADATA	
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2,2),&wsdata);

	//create socket
	SOCKET server_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//init socket
	sockaddr_in sock_add;
	sock_add.sin_family=PF_INET;
	sock_add.sin_addr.s_addr=inet_addr("127.0.0.1");
	sock_add.sin_port=htons(PORT);

	//bind socket
	bind(server_socket,(SOCKADDR*)&sock_add,sizeof(sock_add));

	//wait for the connection of client
	SOCKADDR client_addr;
	int client_addr_size = sizeof(client_addr);
	SOCKET client_socket = accept(server_socket,(SOCKADDR*)&client_socket,&client_addr_size);

	//send info. to client
	char* str="welcome to login!";
	send(client_socket,str,strlen(str)+sizeof(char),NULL);

	//close socket
	closesocket(client_socket);
	closesocket(server_socket);
	WSACleanup();

	system("pause");
	return 0;
}