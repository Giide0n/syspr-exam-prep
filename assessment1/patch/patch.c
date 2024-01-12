#include <sys/fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fdOrigin = open(argv[1], O_RDWR);
    int fdDelta = open(argv[3], O_RDONLY);

    int offset = atoi(argv[2]);
    lseek(fdOrigin, offset, SEEK_SET);

    int n = atoi(argv[4]);
    char diff[n];

    read(fdDelta, diff, n);
    write(fdOrigin, diff, n);
}