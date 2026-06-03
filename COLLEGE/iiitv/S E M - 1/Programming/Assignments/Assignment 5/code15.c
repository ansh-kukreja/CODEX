#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int size1, size2, i = 0, j = 0, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter elements of first array:\n");
    while (i < size1) scanf("%d", &arr1[i++]);

    printf("Enter size of second array: ");
    scanf("%d", &size2);
    printf("Enter elements of second array:\n");
    while (j < size2) scanf("%d", &arr2[j++]);

    i = 0;
    while (i < size1) merged[k++] = arr1[i++];
    j = 0;
    while (j < size2) merged[k++] = arr2[j++];

    printf("Merged array: ");
    i = 0;
    while (i < k) {
        printf("%d ", merged[i]);
        i++;
    }
    return 0;
}
