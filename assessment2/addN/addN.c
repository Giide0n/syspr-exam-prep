#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int sum = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *add(void *arg) {
    char *n = (char *) arg;
    int num = atoi(n);

    pthread_mutex_lock(&m);
    sum += num;
    pthread_mutex_unlock(&m);

    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[argc - 1];

    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i-1], NULL, add, argv[i]);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", sum);
}