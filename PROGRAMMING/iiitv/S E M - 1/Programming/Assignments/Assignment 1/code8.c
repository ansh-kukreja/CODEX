#include<stdio.h> 

int main(){ 

    int n = 10245;
    int ans = 0;

    while(n){
        int bit = n % 10;
        ans = (ans*10) + bit;
        n /= 10;
    }

    printf("Reverse is : %d", ans);
    return 0;
}