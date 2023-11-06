#include <sys/fcntl.h>
#include <unistd.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
    char buff[1];
    int r;

    lseek(fd, 1, SEEK_SET);
    read(fd, buff, 1);
    int w = atoi(buff);

    printf("%d\n", w);
}