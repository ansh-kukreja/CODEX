#include <stdio.h>

int main() {
    int matrix[10][10], size, i = 0, j;
    int mainDiag = 0;

    printf("Enter size of square matrix: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    while (i < size) {
        j = 0;
        while (j < size) {
            scanf("%d", &matrix[i][j]);
            j++;
        }
        i++;
    }

    i = 0;
    while (i < size) {
        mainDiag += matrix[i][i];
        i++;
    }

    printf("Sum of main diagonal = %d\n", mainDiag);
    return 0;
}
