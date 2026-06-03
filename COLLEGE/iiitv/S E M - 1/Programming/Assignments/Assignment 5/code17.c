#include <stdio.h>

int main() {
    int arr[50], size, i = 0, j, k;

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements:\n");
    while (i < size) scanf("%d", &arr[i++]);

    i = 0;
    while (i < size) {
        j = i + 1;
        while (j < size) {
            if (arr[i] == arr[j]) {
                k = j;
                while (k < size - 1) {
                    arr[k] = arr[k + 1];
                    k++;
                }
                size--;
            } else {
                j++;
            }
        }
        i++;
    }

    printf("Array without duplicates: ");
    i = 0;
    while (i < size) printf("%d ", arr[i++]);
    printf("\n");
    return 0;
}
