#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;


void push(int x){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main(){
    int num;

    printf("Enter a decimal number: ");
    scanf("%d",&num);

    if(num == 0){
        printf("Binary: 0\n");
        return 0;
    }

    while(num > 0){
        push(num % 2);
        num = num / 2;
    }

    printf("Binary equivalent: ");
    while(top != -1){
        printf("%d", pop());
    }

    printf("\n");
    return 0;
}