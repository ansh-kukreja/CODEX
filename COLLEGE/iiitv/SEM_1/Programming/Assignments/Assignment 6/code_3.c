#include<stdio.h>

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int i=1;
    while(i<=n){

        int j = n-i;
        while(j){
            printf("_");
            j--;
        }

        int k = 1;
        while(k <= i){
            printf("*");
            k++;
        }

        int l = i-1;
        while(l){  
            printf("*");
            l--;
        };

        printf("\n");
        i++;
    }
}