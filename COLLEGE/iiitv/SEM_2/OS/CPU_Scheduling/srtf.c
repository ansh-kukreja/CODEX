#include <stdio.h>

int main() {
    int n;
    int at[40], bt[40], rt[40], wt[40], tat[40], pid[40];
    int completed = 0, currentTime = 0;
    int prev = -1;
    float avgWT = 0, avgTAT = 0;

    int ganttP[100], ganttT[100];
    int gc = 0;

    printf("Enter number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        pid[i] = i;
    }

    while (completed < n) {
        int idx = -1;
        int minRT = 100000;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && rt[i] > 0) {
                if (rt[i] < minRT) {
                    minRT = rt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            currentTime++;
            continue;
        }

        if (prev != idx) {
            ganttP[gc] = pid[idx];
            ganttT[gc] = currentTime;
            gc++;
            prev = idx;
        }

        rt[idx]--;
        currentTime++;

        if (rt[idx] == 0) {
            completed++;
            tat[idx] = currentTime - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            avgWT += wt[idx];
            avgTAT += tat[idx];
        }
    }

    ganttT[gc] = currentTime;

    avgWT /= n;
    avgTAT /= n;

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nGantt Chart:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < gc; i++) {
        printf("| P%d ", ganttP[i]);
    }
    printf("|\n");

    printf("--------------------------------------------------\n");


    for (int i = 0; i <= gc; i++) {
        printf("%d   ", ganttT[i]);
    }
    printf("\n");

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}