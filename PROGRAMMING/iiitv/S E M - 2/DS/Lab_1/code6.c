#include<stdio.h>

int main() {
    int n, rev;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Reversed: ");
    while (n != 0) {
        printf("%d", n % 10);
        n = n / 10;
    }

    printf("\n\n");

    return 0;
}