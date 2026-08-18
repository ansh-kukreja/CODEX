#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, arrival, burst, remaining, priority;
    int completion, turnaround, waiting;
};

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid = i+1;

        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d",&p[i].arrival);

        printf("Burst Time: ");
        scanf("%d",&p[i].burst);

        printf("Priority (smaller number = higher priority): ");
        scanf("%d",&p[i].priority);

        p[i].remaining = p[i].burst;
    }

    int time = 0, completed = 0;

    int gantt[1000];
    int gindex = 0;

    while(completed < n){

        int highest = -1;
        int bestPriority = INT_MAX;

        for(int i=0;i<n;i++){
            if(p[i].arrival <= time && p[i].remaining > 0){
                if(p[i].priority < bestPriority){
                    bestPriority = p[i].priority;
                    highest = i;
                }
            }
        }

        if(highest == -1){
            gantt[gindex++] = -1;
            time++;
            continue;
        }

        gantt[gindex++] = p[highest].pid;
        p[highest].remaining--;
        time++;

        if(p[highest].remaining == 0){
            completed++;

            p[highest].completion = time;
            p[highest].turnaround =
                p[highest].completion - p[highest].arrival;

            p[highest].waiting =
                p[highest].turnaround - p[highest].burst;
        }
    }

    printf("\n\n");
    float totalWT = 0, totalTAT = 0;

    printf("\n\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++){
        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].priority,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    printf("\n\nGantt Chart:\n|");

    for(int i=0;i<gindex;i++){
        if(gantt[i] == -1)
            printf(" Idle |");
        else
            printf(" P%d |", gantt[i]);
    }

    printf("\n");

    printf("\nAverage Waiting Time = %.2f", totalWT/n);
    printf("\nAverage Turnaround Time = %.2f\n\n", totalTAT/n);

    return 0;
}