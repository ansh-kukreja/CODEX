#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];
pthread_t philosophers[N];
int ids[N];

void think(int i){
    printf("Philosopher %d is thinking\n", i);
    sleep(1);
}

void eat(int i){
    printf("Philosopher %d is EATING\n", i);
    sleep(2);
}

void* philosopher(void* arg){
    int i = *((int*)arg);

    while(1){
        think(i);

        if(i % 2 == 0){
            pthread_mutex_lock(&forks[i]);
            printf("Philosopher %d picked LEFT fork %d\n", i, i);

            pthread_mutex_lock(&forks[(i+1)%N]);
            printf("Philosopher %d picked RIGHT fork %d\n", i, (i+1)%N);
        }
        else{
            pthread_mutex_lock(&forks[(i+1)%N]);
            printf("Philosopher %d picked RIGHT fork %d\n", i, (i+1)%N);

            pthread_mutex_lock(&forks[i]);
            printf("Philosopher %d picked LEFT fork %d\n", i, i);
        }

        eat(i);

        pthread_mutex_unlock(&forks[i]);
        pthread_mutex_unlock(&forks[(i+1)%N]);

        printf("Philosopher %d released forks\n\n", i);
        sleep(1);
    }
    return NULL;
}

int main(){

    for(int i=0;i<N;i++)
        pthread_mutex_init(&forks[i], NULL);

    for(int i=0;i<N;i++){
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for(int i=0;i<N;i++)
        pthread_join(philosophers[i], NULL);

    return 0;
}

// gcc dining_philosophers.c -pthread -o dining
// ./dining