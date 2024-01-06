//
// Created by Benaja on 06/01/2024.
// Test: FS2022 4ibb2 Aufgabe 3
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
    int buf[32]

    int tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    int udpsock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_adress = "127.0.0.1";

    recvfrom(udpsock, &buf, 4096, 0, &server_address, sizeof(server_address));

    printf("Server Port: %d\n", ntohs(server_address.sin_port));
}
