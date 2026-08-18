#include <stdio.h>

int main() {
    int n, x, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    for(i = 0; i < n; i++) {
        if(arr[i] == x) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}