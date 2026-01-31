#include <stdio.h>

int main() {
    int n, tq;
    int bt[10], rt[10], wt[10] = {0}, tat[10];
    int time = 0, remaining;
    int avgTat = 0;
    int avgWT = 0;

    int ganttP[100], ganttT[100];
    int gc = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remaining = n;

    while (remaining > 0) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {

                ganttP[gc] = i + 1;
                ganttT[gc] = time;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } 
                else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remaining--;
                }

                gc++;
            }
        }
    }

    ganttT[gc] = time;

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }


    printf("\n\nProcess\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    for (int i = 0; i < n; i++) {
        avgTat += tat[i];
        avgWT += wt[i];
    }
    avgTat = avgTat / (n);
    avgWT = avgWT / (n);

    printf("\nAvg Turaround Time: %d", avgTat);
    printf("\nAvg Waiting Time: %d\n", avgWT);



    printf("\nGantt Chart:\n");

    for (int i = 0; i < gc; i++) {
        printf("|  P%d  ", ganttP[i]);
    }
    printf("|\n");

    for (int i = 0; i <= gc; i++) {
        printf("%-7d", ganttT[i]);
    }

    printf("\n\n");
    return 0;
}