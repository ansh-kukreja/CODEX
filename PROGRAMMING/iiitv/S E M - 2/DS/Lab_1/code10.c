#include <stdio.h>

int main() {
    int num, binary[32], onesComp[32];
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    int temp = num;
    while (temp > 0) {
        binary[i] = temp % 2;
        temp = temp / 2;
        i++;
    }

    printf("\n1's Complement: ");
    for (int j = i - 1; j >= 0; j--) {
        if (binary[j] == 0)
            onesComp[j] = 1;
        else
            onesComp[j] = 0;

        printf("%d", onesComp[j]);
    }

    printf("\n");
    return 0;
}