#include <stdio.h>
#include "sensor.h"

int main() {
    int n;
    float temps[24];

    printf("Enter number of hours recorded today: ");
    scanf("%d", &n);

    if (n <= 0 || n > 24) {
        printf("Invalid number of hours!\n");
        return 0;
    }

    recordTemperatures(temps, n);

    float maxTemp = findMax(temps, n);
    float minTemp = findMin(temps, n);

    printf("\n-- Daily Temperature Report --\n");
    printf("Maximum Temperature: %.2f C\n", maxTemp);
    printf("Minimum Temperature: %.2f C\n", minTemp);

    return 0;
}



//    gcc main.c sensor.c -o weather
//    ./weather
