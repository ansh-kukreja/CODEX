#include<stdio.h>

int main(){
    char st[40];

    printf("Enter a String: ");
    scanf("%[^\n]", st);

    printf("\n\n%s\n\n", st);
}