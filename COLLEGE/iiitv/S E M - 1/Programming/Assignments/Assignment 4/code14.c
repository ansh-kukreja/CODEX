#include <stdio.h>
#include <math.h>

int main() {
    double x;
    float pi = 3.14159;
    
    printf("Enter a number: ");
    scanf("%lf", &x);

    printf("Pi = %f\n", pi);
    printf("Square root = %lf\n", sqrt(x));
    printf("Cosine = %lf\n", cos(x));
    printf("Exponential = %lf\n", exp(x));
}
