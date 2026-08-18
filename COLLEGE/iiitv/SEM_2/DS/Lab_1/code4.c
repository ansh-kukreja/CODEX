#include<stdio.h>

int power(int i, int j){
    int ans=1;
    for(int k=0; k<j; k++){
        ans *= i;
    }
    return ans;
}

int main(){
    int n;
    printf("Enter a Number : ");
    scanf("%d", &n);

    int ans = 0;
    int i=0;

    while(n !=0 ){
        int bit = n & 1;
        ans = (bit * power(10,i++)) + ans;
        n = n >> 1;
    }

    printf("Binary Representation : %d\n", ans);
}