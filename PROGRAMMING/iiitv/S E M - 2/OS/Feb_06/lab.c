#include <stdio.h>
#include <stdbool.h>

#define N 5

bool lock = false;
bool waiting[N] = {false};


bool test_and_set(bool *target){
    bool rv = *target;
    *target = true;
    return rv;
}

void swap(bool *a, bool *b){
    bool temp = *a;
    *a = *b;
    *b = temp;
}

void hardware_solution(int i){
    bool key;

    do{
        waiting[i] = true;
        key = true;

        while(waiting[i] && key){
            key = test_and_set(&lock);
        }

        waiting[i] = false;

        // Critical Section
        printf("Process %d is in critical section\n", i);

        // Exit Section
        int j = (i + 1) % N;

        while(j != i && !waiting[j]){
            j = (j + 1) % N;
        }

        if(j == i)
            lock = false;
        else
            waiting[j] = false;

        // Remainder Section

    }while(true);
}

int main(){
    hardware_solution(0);
    return 0;
}