#include <stdio.h>

int main () {
    int a=7, b=2, result1;
    float x=7, y=2, result2;
    result1=a/b;
    result2=x/y;
    printf ("Int division (7/2) = %d\n", result1);
    printf ("Float division (7/2) = %.2f\n", result2);
    return 0;
}
