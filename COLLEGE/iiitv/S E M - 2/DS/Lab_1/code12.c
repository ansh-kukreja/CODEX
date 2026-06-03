#include <stdio.h>

int main() {
    int n, scalar;
    int A[20], B[20], result[20];
    int correlation = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter elements of Array A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("\nEnter elements of Array B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    printf("\nEnter scalar value: ");
    scanf("%d", &scalar);

    for (int i = 0; i < n; i++) {
        result[i] = scalar * A[i];
    }

    printf("\nScalar Multiplication Result:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }


    for (int i = 0; i < n; i++) {
        correlation += A[i] * B[i];
    }

    printf("\n\nCorrelation Result = %d\n", correlation);

    return 0;
}