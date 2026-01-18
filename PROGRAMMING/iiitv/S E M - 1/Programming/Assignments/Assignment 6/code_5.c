#include<stdio.h>

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int i=1;
    while(i<=n){

        int j = n-i;
        while(j){
            printf(" ");
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

    int m = n-1;
    for(int i=0; i<m; i++){

        int j = i;
        while(j>=0){
            printf(" ");
            j--;
        }

        int k = m - i;
        for(; k>0; k--){
            printf("*");
        }

        int l = m - i - 1;
        for(; l>0; l--){
            printf("*");
        }

        printf("\n");
    }
}