#include <stdio.h>

int main() {
    char str[] = "Hello";
    float num = 123.4567;

    printf("Right-justified: %10s\n", str);
    printf("Left-justified: %-10s\n", str);
    printf("Default float: %f\n", num);
    printf("Two decimals: %.2f\n", num);
    printf("Four decimals: %.4f", num);
}
