#include <stdio.h>

int main() {
    int num;
    int count = 0, digits[10];

    printf("Enter an integer (more than 4 digits): ");
    scanf("%d", &num);

    int temp = num;
    while (temp > 0) {
        digits[count] = temp % 10;
        temp = temp / 10;
        count++;
    }

    int output = digits[count-1] * 1000 + digits[count-2] * 100 + digits[count-3] * 10 + digits[count-4];
    printf("%10d\n", output);

    return 0;
}
