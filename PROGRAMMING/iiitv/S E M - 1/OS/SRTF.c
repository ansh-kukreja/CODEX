#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;
    int at;   
    int bt; 
    int rt; 
    int ct;  
    int tat; 
    int wt;   
    int finished;
};

int main() {
    int n, completed = 0, time = 0, min_rt, shortest;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].finished = 0;
    }

    while (completed != n) {
        shortest = -1;
        min_rt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].finished == 0 && p[i].rt < min_rt && p[i].rt > 0) {
                min_rt = p[i].rt;
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++; 
            continue;
        }

        p[shortest].rt--;
        time++;

        if (p[shortest].rt == 0) {
            p[shortest].finished = 1;
            completed++;
            p[shortest].ct = time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            avg_tat += p[shortest].tat;
            avg_wt += p[shortest].wt;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}