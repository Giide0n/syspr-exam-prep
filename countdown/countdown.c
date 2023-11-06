#include <unistd.h>
#include <signal.h>
#include <printf.h>
#include <stdlib.h>

volatile int c = 0;

void handle(int signal) {
    if(c > 0) {
        printf("%d\n", --c);
    } else {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    signal(SIGUSR1, handle);
    c = atoi(argv[1]);
    int p_pid = getpid();
    int c_pid = fork();

    if(c_pid == 0) {
        while(c > 0) {
            kill(p_pid, SIGUSR1);
        }
    } else {
        pause();
    }
}