#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("\n\n");

    int n = 9;

    int *arr = (int*)malloc(n * sizeof(int));

    for(int i=0; i<9; i++){
        printf("%d", arr[i]);
    }

    printf("\n\n");
}