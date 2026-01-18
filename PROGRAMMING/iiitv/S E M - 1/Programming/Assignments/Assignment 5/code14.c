#include <stdio.h>

int main() {
    int arr[50], size, i = 0, sum = 0;
    float avg;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    while (i < size) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        i++;
    }

    avg = (float)sum / size;
    printf("Average = %.2f\n", avg);

    return 0;
}
