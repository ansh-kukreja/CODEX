#include <stdio.h>

int main () {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d numbers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("First element = %d\n", arr[0]);
    printf("Last element = %d\n", arr[size - 1]);
    return 0;
}
