#include <stdio.h>

int sumOfArray(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] % 14 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n = 7;
    int arr[] = {4,28,29,49,70,98,190};

    int result = sumOfArray(arr, n);
    printf("\nSum of elements divisible by both 2 and 7: %d\n\n", result);

    return 0;
}
