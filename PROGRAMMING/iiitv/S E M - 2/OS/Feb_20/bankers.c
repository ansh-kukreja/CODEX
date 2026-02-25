#include <stdio.h>

#define MAX 10

int main() {
    int n, m;                    
    int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
    int avail[MAX];
    int finish[MAX] = {0};
    int safeSeq[MAX];
    int work[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&avail[j]);


    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];


    for(int j=0;j<m;j++)
        work[j] = avail[j];

    int count = 0;

    while(count < n){
        int found = 0;

        for(int i=0;i<n;i++){
            if(finish[i]==0){

                int possible = 1;
                for(int j=0;j<m;j++){
                    if(need[i][j] > work[j]){
                        possible = 0;
                        break;
                    }
                }

                if(possible){
                    for(int j=0;j<m;j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found){
            printf("\nSystem is NOT in safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe sequence is:\n");
    for(int i=0;i<n;i++)
        printf("P%d ", safeSeq[i]);

    printf("\n\n");
    return 0;
}

// gcc bankers.c -o bankers
// ./bankers


// Processes = 5
// Resources = 3

// Allocation:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// Maximum:
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3

// Available:
// 3 3 2