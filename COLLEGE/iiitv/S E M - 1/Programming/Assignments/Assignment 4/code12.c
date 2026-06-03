#include <stdio.h>

int main() {
    int num, i = 31;
    printf("Enter decimal number: ");
    scanf("%d", &num);

    printf("Binary: ");
    while(i >= 0) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        i = i - 1;
    }
}
