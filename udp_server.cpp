#include <iostream>
#include <cstring>
#include <winsock2.h>
int main() {
WSADATA w; WSAStartup(MAKEWORD(2,2), &w);
SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
sockaddr_in a{}, c{}; a.sin_family = AF_INET;
a.sin_port = htons(5001); a.sin_addr.s_addr = INADDR_ANY;
bind(s, (sockaddr*)&a, sizeof(a)); char msg[100]{};
int len = sizeof(c); std::cout << "UDP server waiting...\n";
recvfrom(s, msg, sizeof(msg)-1, 0, (sockaddr*)&c, &len);
std::cout << "Client: " << msg << '\n';
const char *reply = "Hello from server";
sendto(s, reply, strlen(reply), 0, (sockaddr*)&c, len);
closesocket(s); WSACleanup();
return 0;
}

//g++ udp_server.cpp -o udp_server -lws2_32
//./udp_server
