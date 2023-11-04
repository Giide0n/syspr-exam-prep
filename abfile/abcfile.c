#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {

    int fdRead = open("abcfile", O_RDWR);

    char buff[1];
    int r;
    do {
        r = read(fdRead, buff, 1);
        char fileName[strlen("abcfile_") + 2];
        sprintf(fileName, "abcfile_%c", buff[0]);
        int fdWrite = open(fileName, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
        write(fdWrite, buff, 1);
    } while (r > 0);
}