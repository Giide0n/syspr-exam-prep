#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    for (int i = 0; i < n; ++i) {
        int pid = fork();
        if(pid == 0) {
            execve(argv[2], NULL, NULL);
            exit(0);
        } else {
            wait(NULL);
        }
    }
}