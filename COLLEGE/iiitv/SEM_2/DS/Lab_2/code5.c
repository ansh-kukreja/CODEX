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
    int size1 = 4;
    int arr1[4] = {1,2,3,4};

    int size2 = 7;
    int arr2[7] = {2,4,5,6,7,8,9};

    int size3 = 0;
    int intersection[200];

    for(int i=0; i<size1; i++){
        if(isPresent(arr1[i], arr2, size2)){
            intersection[size3++] = arr1[i];
        }
    }

    printf("\n\n---- INTERSECTION ----\n");
    for(int i=0; i<size3; i++){
        printf(" %d", intersection[i]);
    }
    printf("\n");

    int mergeSize = 0;
    int merged[200];

    for(int i=0; i<size1; i++){
        merged[mergeSize++] = arr1[i];
    }
    for(int i=0; i<size2; i++){
        merged[mergeSize++] = arr2[i];
    }


    int unionSize = 0;
    int unionArray[200];

    for(int i=0; i<mergeSize; i++){
        if(isPresent(merged[i], unionArray, unionSize) == 0){
            unionArray[unionSize++] = merged[i];
        }
    }

    printf("\n\n---- UNION ----\n");
    for(int i=0; i<unionSize; i++){
        printf(" %d", unionArray[i]);
    }
    printf("\n\n");
}