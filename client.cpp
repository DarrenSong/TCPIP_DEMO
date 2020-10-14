#include<iostream>
#include<string>
#include<stdio.h>
#include<winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
const int BUF_SIZE = 100;
 
int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
 
        //server info
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	
        //create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	connect(sock, (SOCKADDR*)& sockAddr, sizeof(sockAddr));
 
	char infoBuff[MAXBYTE] = { 0 };
	recv(sock, infoBuff, MAXBYTE,NULL);
	cout << "从服务器接受到得信息为：" << infoBuff << endl;
 
 
	closesocket(sock);
	WSACleanup();
 
	system("pause");
	return 0;
}