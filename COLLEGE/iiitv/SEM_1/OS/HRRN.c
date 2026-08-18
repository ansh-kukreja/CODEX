#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int pid[n], arrival[n], burst[n];
    for (int i = 0; i < n; ++i) {
        pid[i] = i + 1;
        printf("Process %d arrival time and burst time: ", pid[i]);
        if (scanf("%d %d", &arrival[i], &burst[i]) != 2) return 0;
    }

    int completed[n];
    for (int i = 0; i < n; ++i) completed[i] = 0;

    int completedCount = 0;
    int current_time = 0;
    int start_time[n], completion_time[n], waiting_time[n], turnaround_time[n];

    for (int i = 0; i < n; ++i) {
        start_time[i] = completion_time[i] = waiting_time[i] = turnaround_time[i] = -1;
    }

    while (completedCount < n) {
        int idx = -1;
        double bestRatio = -1.0;
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && arrival[i] <= current_time) {
                int waiting = current_time - arrival[i];
                double responseRatio = (double)(waiting + burst[i]) / (double)burst[i]; // (W + S)/S
                if (responseRatio > bestRatio) {
                    bestRatio = responseRatio;
                    idx = i;
                } else if (responseRatio == bestRatio) {
                    if (arrival[i] < arrival[idx] || (arrival[i] == arrival[idx] && pid[i] < pid[idx])) {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1) {
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!completed[i] && arrival[i] < nextArrival) nextArrival = arrival[i];
            }
            current_time = nextArrival;
            continue;
        }

        start_time[idx] = current_time;
        completion_time[idx] = start_time[idx] + burst[idx];
        turnaround_time[idx] = completion_time[idx] - arrival[idx];
        waiting_time[idx] = start_time[idx] - arrival[idx];

        current_time = completion_time[idx];
        completed[idx] = 1;
        completedCount++;
    }
     double totalWT = 0.0, totalTAT = 0.0;
    printf("\nPID\tArrival\tBurst\tStart\tCompletion\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\t%d\n",
               pid[i], arrival[i], burst[i],
               start_time[i], completion_time[i],
               waiting_time[i], turnaround_time[i]);
        totalWT += waiting_time[i];
        totalTAT += turnaround_time[i];
    }
    printf("\nAverage waiting time = %.2f\n", totalWT / n);
    printf("Average turnaround time = %.2f\n", totalTAT / n);

    printf("\nGantt chart (process order by start time):\n");
    int order[n];
    for (int i = 0; i < n; ++i) order[i] = i;
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (start_time[order[i]] > start_time[order[j]]) {
                int tmp = order[i]; order[i] = order[j]; order[j] = tmp;
            }

    for (int i = 0; i < n; ++i) {
        printf("| P%d ", pid[order[i]]);
    }
    printf("|\n%d", start_time[order[0]]);
    for (int i = 0; i < n; ++i) {
        printf("\t%d", completion_time[order[i]]);
    }
    printf("\n");

}
