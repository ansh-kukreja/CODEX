#include<stdio.h>

int main() {
    int r, c;
    int a[40][40];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nCorner elements of the matrix are:\n");

    printf("Top Left     : %d\n", a[0][0]);
    printf("Top Right    : %d\n", a[0][c - 1]);
    printf("Bottom Left  : %d\n", a[r - 1][0]);
    printf("Bottom Right : %d\n", a[r - 1][c - 1]);

    return 0;
}
