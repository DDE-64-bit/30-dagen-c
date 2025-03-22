#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORT 1024

void scanPort(char *ip, int port) {
    int sock;
    struct sockaddr_in target;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socketfout");
        return;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Poort %d is open.\n", port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Gebruik: %s <IP-adres>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    printf("Scannen van host: %s\n", ip);

    for (int port = 1; port <= MAX_PORT; port++) {
        scanPort(ip, port);
    }

    return 0;
}
