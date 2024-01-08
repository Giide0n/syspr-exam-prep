//
// Created by Benaja on 08/01/2024.
// Test: HS2022 3ib Aufgabe 5

#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct my_sem {
    pthread_mutex_t m;
    int n; // value
} my_sem_t;

int my_sem_init(my_sem_t *s, int n){
    pthread_mutex_init(&s->m, NULL);
    s->n = n;
    return 0;
}
int my_sem_wait(my_sem_t *s){
    int done = 0;
    while (!done) {
        pthread_mutex_lock(&s->m);
        if (s->n > 0) {
            s->n--;
            done = 1;
        }
        pthread_mutex_unlock(&s->m);
    }
    return 0;
}
int my_sem_post(my_sem_t *s){
    pthread_mutex_lock(&s->m);
    s->n++;
    pthread_mutex_unlock(&s->m);
    return 0;
}

my_sem_t s;

void *start(void *arg) { // runs in a thread
    my_sem_wait(&s); // blocking
    printf("Hello from thread %d\n", (int) pthread_self());
    assert(s.n >= 0);
    my_sem_post(&s);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]); // initial value
    my_sem_init(&s, n);
    assert(s.n == n);
    for (int i = 0; i < n; ++i) {
        pthread_t t;
        pthread_create(&t, NULL, start, NULL);
    }
}