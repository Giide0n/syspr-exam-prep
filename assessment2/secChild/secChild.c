#include <printf.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int c = 0;
    int start = clock();
    do {
        if(fork() == 0) {
            exit(0);
        } else {
            c++;
            wait(NULL);
        }
    } while (clock() - start < CLOCKS_PER_SEC);
    printf("%d\n", c);
}