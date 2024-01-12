#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle(int signal) {
}

int main(int argc, char *argv[]) {
    int count = atoi(argv[1]);
    signal(SIGINT, handle);
    for (int i = 0; i <= count; i++) {
        pause();
    }
}