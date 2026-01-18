#include <stdio.h>

void findElements(int arr[], int n) {
    if (n < 2) {
        printf("Need at least two elements.\n");
        return;
    }

    int largest, secLargest, smallest, secSmallest;
    largest = secLargest = -2147483648;  
    smallest = secSmallest = 2147483647; 

    for (int i = 0; i < n; i++) {
        int val = arr[i];

        if (val > largest) {
            secLargest = largest;
            largest = val;
        } else if (val > secLargest && val != largest) {
            secLargest = val;
        }

        if (val < smallest) {
            secSmallest = smallest;
            smallest = val;
        } else if (val < secSmallest && val != smallest) {
            secSmallest = val;
        }
    }

    printf("Largest: %d\n", largest);
    printf("Second Largest: %d\n", secLargest);
    printf("Smallest: %d\n", smallest);
    printf("Second Smallest: %d\n", secSmallest);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    findElements(arr, n);

    return 0;
}
