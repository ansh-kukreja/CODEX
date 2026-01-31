#include<stdio.h>

// Rotating Array by K Elements

int main(){
    int size = 9;
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k;

    printf("\nEnter the Value of K: ");
    scanf("%d", &k);

    int temp[9];

    for(int i=0; i<k; i++){
        temp[i] = arr[i];
    }

    for(int i = k; i < size; i++){
        arr[i-k] = arr[i];
    }

    int t = 0;
    for(int i = size - k; i < size; i++){
        arr[i] = temp[t++];
    }

    printf("\n---- Rotated Array ----\n");
    for(int i=0; i < size; i++){
        printf(" %d", arr[i]);
    }
    printf("\n\n");
}