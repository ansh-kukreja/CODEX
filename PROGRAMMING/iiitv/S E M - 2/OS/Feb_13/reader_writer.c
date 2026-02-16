#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t rw_mutex;   
sem_t mutex;     

int read_count = 0;
int data = 0;     

void* reader(void* arg) {
    int id = *((int*)arg);

    while(1){
        sem_wait(&mutex);
        read_count++;

        if(read_count == 1){
            sem_wait(&rw_mutex);
        }

        sem_post(&mutex);

        printf("Reader %d is reading data = %d\n", id, data);
        sleep(1);

        sem_wait(&mutex);
        read_count--;

        if(read_count == 0){
            sem_post(&rw_mutex);
        }

        sem_post(&mutex);

        sleep(1);
    }
}

void* writer(void* arg) {
    int id = *((int*)arg);

    while(1){
        sem_wait(&rw_mutex);  

        data++;
        printf("Writer %d updated data to %d\n", id, data);
        sleep(2);

        sem_post(&rw_mutex);

        sleep(1);
    }
}

int main() {

    pthread_t r[5], w[2];

    int rid[5] = {1,2,3,4,5};
    int wid[2] = {1,2};

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    for(int i=0;i<5;i++){
        pthread_create(&r[i], NULL, reader, &rid[i]);
    }

    for(int i=0;i<2;i++){
        pthread_create(&w[i], NULL, writer, &wid[i]);
    }

    for(int i=0;i<5;i++){
        pthread_join(r[i], NULL);
    }

    for(int i=0;i<2;i++){
        pthread_join(w[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}


// gcc reader_writer.c -o rw -lpthread
// ./rw
