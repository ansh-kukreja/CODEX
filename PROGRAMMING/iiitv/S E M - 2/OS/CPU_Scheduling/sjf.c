#include <stdio.h>

int main() {
    int n;
    int at[40], bt[40], wt[40], tat[40], pid[40];
    int completed[40] = {0};

    int start[40], end[40];     
    int order[40];            

    int currentTime = 0, count = 0, gc = 0;
    float avgWT = 0, avgTAT = 0;


    printf("Enter number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
        pid[i] = i;
    }

    while (count < n) {
        int idx = -1;
        int minBT = 100000;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && completed[i] == 0) {
                if (bt[i] < minBT) {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            currentTime++;
        } 
        else{
            start[gc] = currentTime;
            order[gc] = pid[idx];

            wt[idx] = currentTime - at[idx];
            currentTime += bt[idx];
            tat[idx] = wt[idx] + bt[idx];

            end[gc] = currentTime;
            gc++;

            completed[idx] = 1;
            count++;

            avgWT += wt[idx];
            avgTAT += tat[idx];
        }
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }


    printf("\nGantt Chart:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < gc; i++) {
        printf("|  P%d  ", order[i]);
    }
    printf("|\n");

    printf("--------------------------------------------------\n");
    printf("%d", start[0]);
    

    for (int i = 0; i < gc; i++) {
        printf("     %d", end[i]);
    }
    printf("\n");

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n\n", avgTAT);

    return 0;
}