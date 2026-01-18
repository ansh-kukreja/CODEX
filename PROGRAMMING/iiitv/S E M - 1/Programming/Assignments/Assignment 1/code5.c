#include<stdio.h> 

int main(){ 

    int n = 6;
    int ans = 1;

    for(int i = n; i >= 1; i--){
        ans *= i;
    }

    printf("Factorial of %d is : %d", n, ans);
    return 0;
}