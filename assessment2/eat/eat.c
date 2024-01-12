//
// Created by Benaja on 08/01/2024.
// Test: HS2022 3ib Aufgabe 4

#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

#define N_BREAD 3 // per kid
#define N_FORKS 4
#define N_SPOTS 2
#define N_KIDS  7

sem_t sem_spots;
sem_t sem_forks;

void *eat(void *arg){
    int id = (int) arg;
    sem_wait(&sem_spots);
    int i = 0;
    while (i < N_BREAD){
        sem_wait(&sem_forks);
        i++; // Eata da breada mapf mapf
        sem_post(&sem_forks);
    }
    printf("Kid %d is done eating\n", id);
    sem_post(&sem_spots);

}

int main() {
    sem_init(&sem_forks, 0, N_FORKS);
    sem_init(&sem_spots, 0, N_SPOTS);
    for (int i = 0; i < N_KIDS; i++) {
        pthread_t t;
        pthread_create(&t, NULL, eat,(void *) i);
        pthread_detach(t);
    }
    pthread_exit(NULL);
}
