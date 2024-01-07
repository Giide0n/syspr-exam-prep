//
// Created by Benaja on 07/01/2024.
// Test: HS2022 3ib Aufgabe 1
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

volatile int sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* start(void *arg) {
    char *s = arg;
    int len = strlen(s);
    pthread_mutex_lock(&mutex);
    sum += len;
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[]) {

    pthread_t threads[argc - 1];
    for(int i = 1; i < argc; i++) {
        pthread_create(&threads[i-1], NULL, start, argv[i]);

    }
    for(int i = 1; i < argc; i++) {
        pthread_join(threads[i-1], NULL);
    }
    printf("%d\n", sum);
}