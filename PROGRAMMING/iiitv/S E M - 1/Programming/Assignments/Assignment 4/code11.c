#include <stdio.h>

int main() {
    char bin[32];
    int i = 0, dec = 0, base = 1, len = 0;

    printf("Enter binary string: ");
    scanf("%s", bin);

    while(bin[len] != '\0')
        len = len + 1;

    i = len - 1;
    while(i >= 0) {
        if(bin[i] == '1')
            dec = dec + base;
        base = base * 2;
        i = i - 1;
    }

    printf("Decimal = %d", dec);
}
