#include<stdio.h>

int main() {
    int a,b,c,d,e;

    printf("\nEnter first integer: ");
    scanf("%d", &a);
    printf("Enter second integer: ");
    scanf("%d", &b);
    printf("Enter third integer: ");
    scanf("%d", &c);
    printf("Enter fourth integer: ");
    scanf("%d", &d);
    printf("Enter fifth integer: ");
    scanf("%d", &e);

    printf("Average: %d \n\n", (a + b + c + d + e) / 5);

    return 0;
}