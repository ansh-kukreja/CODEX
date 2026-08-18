#include <stdio.h>

int rotate(int num) {
    int original = num;
    int digits = 0;
    int temp = num;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    int power = 1;
    for (int i = 1; i < digits; i++) {
        power *= 10;
    }

    int rotated = num;
    int count = 0;

    while (1){
        int firstDigit = rotated / power;
        rotated = (rotated % power) * 10 + firstDigit;
        count++;

        if (rotated == original){
            break;
        }
    }

    return count;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int result = rotate(n);
    printf("It takes %d left rotations to return %d to its original state", result, n);

    return 0;
}
