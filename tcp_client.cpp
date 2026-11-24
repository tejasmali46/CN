#include <iostream>
#include <cstring>
#include <winsock2.h>
int main() {
WSADATA w; WSAStartup(MAKEWORD(2,2), &w);
SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
sockaddr_in a{}; a.sin_family = AF_INET;
a.sin_port = htons(5000); a.sin_addr.s_addr = inet_addr("127.0.0.1");
connect(s, (sockaddr*)&a, sizeof(a));
const char *msg = "Hello from client";
send(s, msg, strlen(msg), 0); char reply[100]{};
recv(s, reply, sizeof(reply)-1, 0);
std::cout << "Server: " << reply << '\n';
closesocket(s); WSACleanup();
return 0;
}

//g++ tcp_client.cpp -o client.exe -lws2_32
//.\client.exe
