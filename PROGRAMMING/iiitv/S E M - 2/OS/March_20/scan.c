#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int requests[100], n, head, disk_size, direction;
    int seek_count = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size (max cylinder number): ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    sort(requests, n);

    int left[100], right[100];
    int l = 0, r = 0;

    for(int i = 0; i < n; i++) {
        if(requests[i] < head)
            left[l++] = requests[i];
        else
            right[r++] = requests[i];
    }

    if(direction == 0)
        left[l++] = 0;
    else
        right[r++] = disk_size - 1;

    printf("\nSeek Sequence: ");

    if(direction == 1) { 
        for(int i = 0; i < r; i++) {
            printf("%d ", right[i]);
            seek_count += abs(head - right[i]);
            head = right[i];
        }

        for(int i = l - 1; i >= 0; i--) {
            printf("%d ", left[i]);
            seek_count += abs(head - left[i]);
            head = left[i];
        }
    }
    else {
        for(int i = l - 1; i >= 0; i--) {
            printf("%d ", left[i]);
            seek_count += abs(head - left[i]);
            head = left[i];
        }

        for(int i = 0; i < r; i++) {
            printf("%d ", right[i]);
            seek_count += abs(head - right[i]);
            head = right[i];
        }
    }

    printf("\nTotal Seek Operations: %d\n", seek_count);

    return 0;
}



// Requests: 80 180 41 122 10 124 65 67
// Head: 50
// Disk size: 200
// Direction: 1