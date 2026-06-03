#include <stdio.h>

int main () {
    int a;
    float b, result;
    printf ("Enter a integer value: ");
    scanf ("%d", &a);
    printf ("Enter a float value: ");
    scanf ("%f", &b);
    result = (float)a + b;
    printf ("Result of a + b: %f\n", result);
    return 0;
}
