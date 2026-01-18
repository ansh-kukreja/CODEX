#include <stdio.h>

int main() {
    int n;
    int bt[20], wt[20], tat[20];
    int i;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("\n--Enter Burst Time for each Process--\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\t   Burst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    float avgWT = 0;
    float avgTAT = 0;
    for(int i=0; i<n; i++){
        avgTAT += tat[i];
        avgWT += wt[i];
    }
    avgWT /= n;
    avgTAT /= n;
    printf("\n Average Waiting Time: %.2f", avgWT);
    printf("\n Average Turnaround Time: %.2f\n\n", avgTAT);

    for(int i=0; i<n; i++){
        printf("| P%d ", i+1);
    }
    printf("|\n\n");

    return 0;
}