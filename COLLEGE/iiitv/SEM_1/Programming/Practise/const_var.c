#include<stdio.h> 

int main(){ 
    
    const int n;

    printf("Enter Value of constant: ");
    scanf("%d", &n);

    printf("Const Value is : %d", n);

    printf("\nAgain Enter Value of constant: ");
    scanf("%d", &n);

    printf("Const Value is : %d", n);
    return 0;
}