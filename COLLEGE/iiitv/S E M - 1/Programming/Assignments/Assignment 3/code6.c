#include <stdio.h>
#include <math.h>

int main () {
    int num, temp, count=0, total=0, onedigit;
    printf ("Enter a Numbers: ");
    scanf ("%d", &num);
    temp=num;
    while (temp!=0) {
        temp/=10;
        count++;
    }
    temp=num;
    while (temp!=0) {
        onedigit=temp%10;
        total+=pow(onedigit, count);
        temp /= 10;
    }
    if(total==num){
        printf ("%d is a Armstrong number", num);
    }
    else {
        printf("%d is not a Armstrong number", num);
    }
    return 0;
}