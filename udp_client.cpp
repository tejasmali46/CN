#include <iostream>
#include <cstring>
#include <winsock2.h>
int main() {
WSADATA w; WSAStartup(MAKEWORD(2,2), &w);
SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
sockaddr_in a{}; a.sin_family = AF_INET;
a.sin_port = htons(5001); a.sin_addr.s_addr = inet_addr("127.0.0.1");
const char *msg = "Hello from client";
sendto(s, msg, strlen(msg), 0, (sockaddr*)&a, sizeof(a));
char reply[100]{}; int len = sizeof(a);
recvfrom(s, reply, sizeof(reply)-1, 0, (sockaddr*)&a, &len);
std::cout << "Server: " << reply << '\n';
closesocket(s); WSACleanup();
return 0;
}

//g++ udp_client.cpp -o udp_client -lws2_32
//./udp_client
