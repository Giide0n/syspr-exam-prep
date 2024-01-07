
#include <sys/socket.h>
#include <unistd.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sockets[2];
    char buf;

    socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);

    if(fork() == 0) {
        read(sockets[1], &buf, 1);
        write(sockets[1], &buf, 1);
        exit(0);
    } else {
        write(sockets[0], argv[1], 1);
        read(sockets[0], &buf, 1);
        printf("%c\n", buf);
    }
}