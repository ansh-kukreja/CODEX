#include<stdio.h>

int main(){
    int a = 5;
    float b = 2.5;

    int implicit = a * b;

    int explicit = (float)a * b;

    printf("\nImplicit Typecasting: %.2f \n\n", a*b);
    printf("Explicit Typecasting: %.2f \n\n", a*b);
}