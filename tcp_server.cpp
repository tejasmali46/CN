#include <iostream>
#include <cstring>
#include <winsock2.h>
int main() {
WSADATA w; WSAStartup(MAKEWORD(2,2), &w);
SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
sockaddr_in a{}; a.sin_family = AF_INET;
a.sin_port = htons(5000); a.sin_addr.s_addr = INADDR_ANY;
bind(s, (sockaddr*)&a, sizeof(a)); listen(s, 1);
std::cout << "TCP server waiting...\n";
SOCKET c = accept(s, NULL, NULL); char msg[100]{};
recv(c, msg, sizeof(msg)-1, 0);
std::cout << "Client: " << msg << '\n';
const char *reply = "Hello from server";
send(c, reply, strlen(reply), 0);
closesocket(c); closesocket(s); WSACleanup();
return 0;
}
// g++ tcp_server.cpp -o server.exe -lws2_32
//.\server.exe
