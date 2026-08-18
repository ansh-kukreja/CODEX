#include <stdio.h>

int main() {
    int matrix[10][10], rows, cols, i = 0, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements:\n");
    while (i < rows) {
        j = 0;
        while (j < cols) {
            scanf("%d", &matrix[i][j]);
            j++;
        }
        i++;
    }

    printf("Matrix:\n");
    i = 0;
    while (i < rows) {
        j = 0;
        while (j < cols) {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
