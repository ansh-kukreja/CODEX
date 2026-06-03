#include <stdio.h>

int main() {
    int n;
    int m = 3;
    int i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int alloc[n][m], max[n][m], avail[m];
    int need[n][m], finish[n], safeSeq[n];


    printf("\nEnter Available Resources:\n");
    printf("A = ");
    scanf("%d", &avail[0]);
    printf("B = ");
    scanf("%d", &avail[1]);
    printf("C = ");
    scanf("%d", &avail[2]);
    
    printf("\nEnter Allocation Matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Need Matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
        finish[i] = 0;
    }

    int count = 0;

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("\nSystem is in UNSAFE state.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\n");
    printf("Safe Sequence is: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]+1);
    printf("\n");

    return 0;
}


// Available  3 3 2

// Enter Allocation Matrix (A B C for each process):
// 0   1   0
// 3   0   2
// 2   0   0
// 2   1   1
// 0   0   2


// Enter Max Need Matrix (A B C for each process):
// 7   5   3
// 3   2   2
// 9   0   2
// 4   2   2
// 5   3   3