#include<stdio.h>

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){

        int j = i;
        while(j>0){
            printf(" ");
            j--;
        }

        int k = n - i;
        for(; k>0; k--){
            printf("*");
        }

        int l = n - i - 1;
        for(; l>0; l--){
            printf("*");
        }

        printf("\n");
    }
}