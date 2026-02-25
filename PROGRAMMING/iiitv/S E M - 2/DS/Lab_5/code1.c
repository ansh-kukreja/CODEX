#include <stdio.h>


#define MAX 5

int stack[MAX];
int top = -1;

void push(int value){
    if(top == MAX-1){
        printf("Stack overflow! Cannot push element");
        return;
    }
    top++;
    stack[top] = value;
    printf("Element Added!");
}

void pop(){
    if(top == -1){
        printf("Stack underflow! Stack is empty\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    int c, value;

    while(1){
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&c);

        switch(c){
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}