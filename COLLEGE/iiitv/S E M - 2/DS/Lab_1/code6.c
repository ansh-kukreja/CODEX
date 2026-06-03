#include<stdio.h>

int main(){
    int n;
    int rev = 0;

    printf("\n\nEnter a Number: ");
    scanf("%d", &n);

    while(n != 0){
        int bit = n%10;
        rev = (rev*10) + bit;
        n /= 10;
    }

    printf("Reversed: %d\n\n", rev);
}