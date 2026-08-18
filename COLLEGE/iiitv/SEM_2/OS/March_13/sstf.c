#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[100], visited[100] = {0};
    int n, head, seek_time = 0;

    printf("\nEnter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(int i = 0; i < n; i++) {
        int min = 100000, index = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = abs(head - request[j]);
                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        seek_time += min;
        head = request[index];
        visited[index] = 1;

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek_time);

    return 0;
}

// 8
// 98 183 37 122 14 124 65 67
// 50