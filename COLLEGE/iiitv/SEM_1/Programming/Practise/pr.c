#include<stdio.h> 
#include<string.h>


typedef struct{
    char name[100];
    long phoneNumber;
    char street[100];
} ClassF;


int main(){ 

    ClassF arr[4];

    printf("Enter Phone : ");
    scanf("%ld", &(*arr).phoneNumber);

    printf("Phone : %d", arr[0].phoneNumber);
    

    
    return 0;
}