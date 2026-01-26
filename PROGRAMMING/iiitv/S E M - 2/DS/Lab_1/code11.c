#include<stdio.h>
#include<math.h>

int main() {
    int n;
    float arr[50];
    float sum = 0, mean = 0, sd = 0;
    float min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    min = max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min){
            min = arr[i];
        }
        if (arr[i] > max){
            max = arr[i];
        }
    }

    mean = sum / n;
    
    printf("\nMinimum value = %.2f", min);
    printf("\nMaximum value = %.2f", max);
    printf("\nSum of elements = %.2f", sum);
    printf("\nMean = %.2f", mean);

    return 0;
}