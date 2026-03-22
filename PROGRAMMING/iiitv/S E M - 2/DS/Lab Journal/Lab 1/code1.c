#include <stdio.h>
#include <math.h>

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    // Input elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Initialize
    float min = arr[0], max = arr[0];
    float sum = 0.0;

    // Calculate min, max, sum
    for(int i = 0; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
        
        sum += arr[i];
    }

    // Mean
    float mean = sum / n;

    // Standard Deviation
    float variance = 0.0;
    for(int i = 0; i < n; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    variance = variance / n;
    float stdDev = sqrt(variance);

    // Output results
    printf("\nMinimum value: %.2f", min);
    printf("\nMaximum value: %.2f", max);
    printf("\nSum: %.2f", sum);
    printf("\nMean: %.2f", mean);
    printf("\nStandard Deviation: %.2f", stdDev);

    return 0;
}