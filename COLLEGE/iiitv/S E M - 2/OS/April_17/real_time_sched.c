#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int execution_time;
    int deadline;
    int remaining_time;
    int completed;
} Process;

int main() {
    int n, time = 0, completed = 0;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].id = i + 1;

        printf("Execution Time: ");
        scanf("%d", &p[i].execution_time);

        printf("Deadline: ");
        scanf("%d", &p[i].deadline);

        p[i].remaining_time = p[i].execution_time;
        p[i].completed = 0;
    }

    printf("\nExecution Order:\n");

    while(completed < n) {
        int idx = -1;
        int earliest_deadline = 9999;

        for(int i = 0; i < n; i++) {
            if(p[i].remaining_time > 0 && p[i].deadline < earliest_deadline) {
                earliest_deadline = p[i].deadline;
                idx = i;
            }
        }

        if(idx != -1) {
            printf("Time %d: Process P%d\n", time, p[idx].id);

            p[idx].remaining_time--;
            time++;

            if(p[idx].remaining_time == 0) {
                p[idx].completed = 1;
                completed++;
            }
        } else {
            time++;
        }
    }

    printf("\nAll processes completed.\n");
    return 0;
}


// Processes: 3

// P1: Exec=3, Deadline=7  
// P2: Exec=2, Deadline=4  
// P3: Exec=1, Deadline=2