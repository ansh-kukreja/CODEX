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

    i = 0;
    while (i < rows) {
        int rowSum = 0;
        j = 0;
        while (j < cols) rowSum += matrix[i][j++];
        printf("Row %d sum = %d\n", i+1, rowSum);
        i++;
    }

    j = 0;
    while (j < cols) {
        int colSum = 0, k = 0;
        while (k < rows) colSum += matrix[k++][j];
        printf("Column %d sum = %d\n", j+1, colSum);
        j++;
    }

    return 0;
}
