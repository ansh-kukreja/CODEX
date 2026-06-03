#include <stdio.h>
#include <math.h>

int main() {
    int bin, dec = 0, i = 0, rem;
    printf("Enter a binary number: ");
    scanf("%d", &bin);

    while(bin > 0) {
        rem = bin % 10;
        dec += rem * pow(2, i++);
        bin /= 10;
    }

    printf("Decimal : %d", dec);
}
