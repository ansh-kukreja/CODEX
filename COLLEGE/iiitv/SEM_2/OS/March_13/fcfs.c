// Platter > surface > track > sector

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i;
    int request[100];
    int seek_time = 0;

    printf("\nEnter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++) {
        seek_time += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", seek_time);

    return 0;
}


// 4
// 82 170 43 140
// 50