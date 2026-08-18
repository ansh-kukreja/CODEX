#include <stdio.h>

int main() {
    float arr[5];
    float sum;
    printf("Enter 5 float values:\n");
    scanf("%f", &arr[0]);
    scanf("%f", &arr[1]);
    scanf("%f", &arr[2]);
    scanf("%f", &arr[3]);
    scanf("%f", &arr[4]);
    sum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
    printf("Sum of elements = %f\n", sum);
    return 0;
}
