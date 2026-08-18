#include <stdio.h>

int main () {
    double num;
    printf ("Enter a number: ");
    scanf ("%lf", &num);
    printf ("The value you entered is: %.2lf\n", num);
    return 0;
}
