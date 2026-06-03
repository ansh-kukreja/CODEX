#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void CLOOK(int requests[], int n, int head, int direction) {
    int seek_count = 0;
    int distance, cur_track;

    qsort(requests, n, sizeof(int), cmpfunc);

    int left[n], right[n];
    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[l++] = requests[i];
        else if (requests[i] > head)
            right[r++] = requests[i];
    }

    printf("\nSeek Sequence:\n");

    if (direction == 1) {
        for (int i = 0; i < r; i++) {
            cur_track = right[i];
            distance = abs(cur_track - head);
            seek_count += distance;

            printf("%d -> ", cur_track);
            head = cur_track;
        }

        if (l > 0) {
            head = left[0];
        }

        for (int i = 0; i < l; i++) {
            cur_track = left[i];
            distance = abs(cur_track - head);
            seek_count += distance;

            printf("%d -> ", cur_track);
            head = cur_track;
        }
    }
    else {
        for (int i = l - 1; i >= 0; i--) {
            cur_track = left[i];
            distance = abs(cur_track - head);
            seek_count += distance;

            printf("%d -> ", cur_track);
            head = cur_track;
        }

        if (r > 0) {
            printf("(jump to %d) -> ", right[r - 1]);
            head = right[r - 1]; 
        }

        for (int i = r - 1; i >= 0; i--) {
            cur_track = right[i];
            distance = abs(cur_track - head);
            seek_count += distance;

            printf("%d -> ", cur_track);
            head = cur_track;
        }
    }

    printf("\n\nTotal Seek Operations = %d\n", seek_count);
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(requests) / sizeof(requests[0]);

    int head = 50;
    int direction = 1;

    CLOOK(requests, n, head, direction);

    return 0;
}