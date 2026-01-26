#include<stdio.h>

int main(){
    int marks[5];
    int sum = 0;

    for(int i=0; i<5; i++){
        printf("Enter marks of %d subject: ", i+1);
        scanf("%d", &marks[i]);
    }

    for(int i=0; i<5; i++){
        sum += marks[i];
    }
    float per = (sum / 500.0) * 100;

    printf("Percentage: %.2f%%\n\n", per);
}