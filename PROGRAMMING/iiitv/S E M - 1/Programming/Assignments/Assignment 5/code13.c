#include <stdio.h>

int main() {
    int arr[100], size, i = 0, max, min;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    while (i < size) {
        scanf("%d", &arr[i]);
        i++;
    }

    max = arr[0];
    min = arr[0];
    i = 1;
    
    while (i < size) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        i++;
    }

    printf("Maximum: %d\nMinimum: %d\n", max, min);
    return 0;
}
