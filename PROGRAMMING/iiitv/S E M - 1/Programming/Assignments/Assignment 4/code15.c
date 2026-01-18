#include <stdio.h>
#include <math.h>

int main() {
    double num;
    printf("Enter a floating-point number: ");
    scanf("%lf", &num);

    printf("floor(%lf) = %lf\n", num, floor(num));
    printf("ceil(%lf) = %lf\n", num, ceil(num));
}
