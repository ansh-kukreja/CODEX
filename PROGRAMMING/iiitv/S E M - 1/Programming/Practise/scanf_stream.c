#include<stdio.h> 

int main(){ 
    int val;
    float flo;
    printf("Enter Values: ");
// *****************************
    scanf("%d %f", &val, &flo);
// *****************************

    printf("\nValue of Val is: %d", val);
    printf("\nValue of Flo is: %f", flo);
    return 0;
}