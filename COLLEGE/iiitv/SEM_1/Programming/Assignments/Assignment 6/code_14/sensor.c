#include <stdio.h>
#include "sensor.h"

void recordTemperatures(float temps[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter temperature for hour %d: ", i + 1);
        scanf("%f", &temps[i]);
    }
}

float findMax(float temps[], int n) {
    float max = temps[0];
    int i;
    for (i = 1; i < n; i++) {
        if (temps[i] > max)
            max = temps[i];
    }
    return max;
}

float findMin(float temps[], int n) {
    float min = temps[0];
    int i;
    for (i = 1; i < n; i++) {
        if (temps[i] < min)
            min = temps[i];
    }
    return min;
}
