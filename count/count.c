#include <unistd.h>
#include <signal.h>
#include <printf.h>

volatile int counting = 1;

void handle(int signal) {
    counting = 0;
}

int main() {
    int counter = 0;
    signal(SIGALRM, handle);
    alarm(1);

    while(counting) {
        counter++;
    }

    printf("counted to %d", counter);
}