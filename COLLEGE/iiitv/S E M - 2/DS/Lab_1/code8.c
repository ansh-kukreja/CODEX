#include<stdio.h>

int main(){
    int a = 5;
    float b = 2.5;

    int implicit = a * b;

    int explicit = a * (int)b;

    printf("\nImplicit Typecasting: %.2d \n\n", implicit);
    printf("Explicit Typecasting: %.2d \n\n", explicit);
}