#include<stdio.h>

int main(){
    int size1 = 4;
    int arr1[4] = {1,2,3,4};

    int size2 = 7;
    int arr2[7] = {5,6,7,8,9,10,11};

    int size3 = size1 + size2;
    int arr3[11];

    int index = 0;

    for(int i=0; i<size1; i++){
        arr3[index++] = arr1[i];
    }
    for(int i=0; i<size2; i++){
        arr3[index++] = arr2[i];
    }

    printf("\n\n---- Merged Array ----\n");
    for(int i=0; i < size3; i++){
        printf(" %d", arr3[i]);
    }
    printf("\n\n");
}