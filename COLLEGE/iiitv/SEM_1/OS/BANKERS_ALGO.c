#include <stdio.h>

int main() {
    int n, m;
    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10] = {0}, safeSeq[10];
    int count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("\nEnter the Allocation Matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter the Maximum Requirement Matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter the Available Resources (of %d types):\n", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Need Matrix: Need[i][j] = Max[i][j] - Alloc[i][j]
    printf("\nThe Need Matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }


    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == m) {
                    for (int k = 0; k < m; k++){
                        avail[k] += alloc[i][k]; 
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;      
                    found = 1;
                }
            }
        }

        // If no process was found in this iteration, system is in unsafe state
        if (found == 0) {
            printf("\nSystem is in UNSAFE state. No safe sequence exists.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}


// number of processes: 5
// number of resource types: 3

// Allocation Matrix:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// Maximum Requirement Matrix:
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3

// Available Resources:
// 3 3 2
