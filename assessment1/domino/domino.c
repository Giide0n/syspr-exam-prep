#include <stdlib.h>
#include <unistd.h>
#include <printf.h>

int main(int argc, char *argv[]) {
    int count = atoi(argv[1]);
    for (int i = 0; i < count; ++i) {
        int pid = fork();
        if(pid == 0) {
            printf("%d set up\n", getpid());
        } else {
            wait(NULL);
            printf("%d fallen\n", pid);
            exit(0);
        }
    }
    printf("oops...\n");
}