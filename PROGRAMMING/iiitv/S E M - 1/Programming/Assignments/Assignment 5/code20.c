#include <stdio.h>

int main() {
    int arr[50], size, position, value, i = 0;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    while (i < size) scanf("%d", &arr[i++]);

    printf("Enter position (0-based index): ");
    scanf("%d", &position);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    i = size;
    while (i > position) {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[position] = value;
    size++;

    printf("Array after insertion: ");
    i = 0;
    while (i < size) printf("%d ", arr[i++]);
    printf("\n");

    return 0;
}
