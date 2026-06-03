#include <stdio.h>
int main () {
    short shortNum;
    long longNum;
    unsigned int unsignNum;
    printf ("Enter a short integer value: ");
    scanf ("%d", &shortNum);
    printf ("Enter a long integer value: ");
    scanf ("%ld", &longNum);
    printf ("Enter an unsigned integer value: ");
    scanf ("%u", &unsignNum);
    printf ("Size of short: %d bytes\n", sizeof(shortNum));
    printf ("Size of long: %d bytes\n", sizeof(longNum));
    printf ("Size of unsigned int: %d bytes\n", sizeof(unsignNum));
    return 0;
}
