#include<stdio.h>

int power(int i, int j){
    int ans=1;
    for(int k=0; k<j; k++){
        ans *= i;
    }
    return ans;
}

int main(){
    int binary;
    printf("Enter Binary Number: ");
    scanf("%d",  &binary);

    int decimal = 0;
    int i = 0;

    while(binary > 0){
        int digit = binary % 10;
        decimal += power(2,i++) * digit;
        binary /= 10;
    }

    printf("Decimal: %d\n\n", decimal);
}
