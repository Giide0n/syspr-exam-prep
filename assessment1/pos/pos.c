#include <sys/fcntl.h>
#include <unistd.h>
#include <printf.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    lseek(fd, 1, SEEK_SET);
    fork();
    printf("%d: %lld\n", getpid(), lseek(fd, 0, SEEK_CUR));
}