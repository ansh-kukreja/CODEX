#include <stdio.h>

int main() {
    int temp;
    printf("Enter temperature in Celsius: ");
    scanf("%d", &temp);

    if(temp > 30) printf("Hot Temperature");
    else if(temp < 15) printf("Cold Temperature");
    else printf("Moderate Temperature");
}
