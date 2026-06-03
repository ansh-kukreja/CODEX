#include<stdio.h> 

int main(){ 
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){

        for(int j=0; j<=i; j++){
            printf("*");
        }

        int k = (n-i) * 2;
        while(k>0){
            printf(" ");
            k--;
        }

        for(int j=0; j<=i; j++){
            printf("*");
        }

        printf("\n");
    }

    for(int i=1; i<n; i++){

        int j = n-i;
        while(j>0){
            printf("*");
            j--;
        }

        for(int k = (i + 1) * 2; k>0; k--){
            printf(" ");
        }


        j = n-i;
        while(j>0){
            printf("*");
            j--;
        }

        printf("\n");
    }
    
    return 0;
}