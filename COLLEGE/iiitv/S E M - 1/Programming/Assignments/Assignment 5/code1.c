#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    printf("Enter time in hh mm ss format: ");
    scanf("%d %d %d", &hours, &minutes, &seconds);
    printf("Time is: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
