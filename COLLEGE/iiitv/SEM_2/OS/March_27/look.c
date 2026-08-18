#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void LOOK(int requests[], int n, int head, int direction) {
    int seek_count = 0;
    int distance, cur_track;

    qsort(requests, n, sizeof(int), cmpfunc);

    int left[n], right[n];
    int l = 0, r = 0;

    for(int i = 0; i < n; i++) {
        if(requests[i] < head)
            left[l++] = requests[i];
        else if (requests[i] > head)
            right[r++] = requests[i];
    }

    for (int i = 0; i < n; i++) {
        if (requests[i] == head) {
            printf("Servicing %d (no seek)\n", head);
            break;
        }
    }

    printf("\nSeek Sequence:\n");

    for (int run = 0; run < 2; run++) {

        if (direction == 0) {
            for (int i = l - 1; i >= 0; i--) {
                cur_track = left[i];

                distance = abs(cur_track - head);
                seek_count += distance;

                printf("%d -> ", cur_track);
                head = cur_track;
            }
            direction = 1;
        }
        else if (direction == 1) {
            for (int i = 0; i < r; i++) {
                cur_track = right[i];

                distance = abs(cur_track - head);
                seek_count += distance;

                printf("%d -> ", cur_track);
                head = cur_track;
            }
            direction = 0;
        }
    }

    printf("\n\nTotal Seek Operations = %d\n", seek_count);
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(requests) / sizeof(requests[0]);

    int head = 50;
    int direction = 1;

    LOOK(requests, n, head, direction);

    return 0;
}