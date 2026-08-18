#include <stdio.h>

struct Process {
    int pid;
    int at;   
    int bt; 
    int priority;
    int rt;     
    int wt;   
    int tat;     
    int completed;
};

int main() {
    int n, completed = 0, t = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Arrival Time, Burst Time, and Priority for Process %d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].rt = p[i].bt;     
        p[i].completed = 0;
    }

    int total_idle = 0;
    int prev = 0;

    printf("\n------------------------------------------------------------");
    printf("\nGantt Chart (process execution order):\n");

    while (completed != n) {
        int idx = -1;
        int highestPriority = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].completed == 0 && p[i].priority < highestPriority) {
                highestPriority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            printf(" P%d |", p[idx].pid);
            p[idx].rt--;

            if (p[idx].rt == 0) {
                p[idx].completed = 1;
                completed++;
                p[idx].tat = t + 1 - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                avgWT += p[idx].wt;
                avgTAT += p[idx].tat;
            }
        } else {
            printf(" Idle |");
            total_idle++;
        }
        t++;
    }

    printf("\n------------------------------------------------------------");

    avgWT /= n;
    avgTAT /= n;

    printf("\n\nProcess\tAT\tBT\tPriority\tWT\tTAT");
    printf("\n------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t\t%d\t%d",
               p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    printf("\n------------------------------------------------------------");
    printf("\nAverage Waiting Time     : %.2f", avgWT);
    printf("\nAverage Turnaround Time  : %.2f", avgTAT);
    printf("\n------------------------------------------------------------\n");

    return 0;
}
