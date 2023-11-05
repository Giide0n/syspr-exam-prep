#include <stdio.h>
#include <pthread.h>

volatile int flag = 0;

void *printName(void *name) {
    while(!flag){}
    char *s = (char*) name;
    printf("%s\n", s);
    return 0;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        pthread_t p;
        pthread_create(&p, NULL, printName, argv[i]);
        pthread_detach(p);
    }

    printf("Press ENTER to start:");
    getchar();

    flag = 1;
    pthread_exit(0);
}