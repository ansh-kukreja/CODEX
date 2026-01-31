#include<stdio.h>

int isPresent(int a, int arr[], int size){
    for(int i=0; i<size; i++){
        if(arr[i] == a){
            return 1;
        }
    }
    return 0;
}

int main(){
    int size = 7;
    int arr1[7] = {1,2,4,2,5,4,6};

    int size2 = 0;
    int arr2[7];

    for(int i=0; i<size; i++){
        if(isPresent(arr1[i], arr2, size2) == 0){
            arr2[size2++] = arr1[i];
        }
    }

    printf("\n\n---- Removed Duplicates ----\n");
    for(int i=0; i<size2; i++){
        printf(" %d", arr2[i]);
    }
    printf("\n\n");
}