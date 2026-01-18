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
    int n, completed = 0, time = 0, max_rt, longest;
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
        longest = -1;
        max_rt = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].finished == 0 && p[i].rt > max_rt) {
                max_rt = p[i].rt;
                longest = i;
            }
        }

        if (longest == -1) {
            time++;
            continue;
        }

        p[longest].rt--;
        time++;

        if (p[longest].rt == 0) {
            p[longest].finished = 1;
            completed++;
            p[longest].ct = time;
            p[longest].tat = p[longest].ct - p[longest].at;
            p[longest].wt = p[longest].tat - p[longest].bt;
            avg_tat += p[longest].tat;
            avg_wt += p[longest].wt;
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
