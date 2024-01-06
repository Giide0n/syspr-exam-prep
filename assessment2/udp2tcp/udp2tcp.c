//
// Created by Benaja on 06/01/2024.
// Test: FS2022 4ibb2 Aufgabe 3
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define UDP_PORT 7070
#define TCP_PORT 8080
#define BUFFER_SIZE 4096

struct sockaddr_in addr;

void initAddr() {
    const char *host = "0.0.0.0";
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(UDP_PORT);
    inet_pton(AF_INET, host, &addr.sin_addr);
}

int main() {
    int udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
    int tcp_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sender_addr;
    char buffer[BUFFER_SIZE];
    socklen_t sender_addr_size = sizeof(sender_addr);

    initAddr();
    bind(udp_sock, (struct sockaddr *)&addr, sizeof(addr));

    recvfrom(udp_sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&sender_addr, &sender_addr_size);

    struct sockaddr_in tcp_server_addr = sender_addr;
    tcp_server_addr.sin_port = htons(TCP_PORT);

    connect(tcp_sock, (struct sockaddr *)&tcp_server_addr, sizeof(tcp_server_addr));
    send(tcp_sock, buffer, BUFFER_SIZE, 0);

    int received_bytes = recvfrom(tcp_sock, buffer, BUFFER_SIZE, 0);
    write(STDOUT_FILENO, buffer, received_bytes);

    close(tcp_sock);
    close(udp_sock);

    return 0;
}
