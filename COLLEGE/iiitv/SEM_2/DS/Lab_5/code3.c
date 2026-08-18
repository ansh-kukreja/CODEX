#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100

char stack[MAX];
int top = -1;


void push(char x){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}


char pop(){
    if(top == -1)
        return '\0';
    return stack[top--];
}

int isMatchingPair(char open, char close){
    if(open=='(' && close==')') return 1;

    else if(open=='{' && close=='}') return 1;

    else if(open=='[' && close==']') return 1;

    return 0;
}


int isBalanced(char exp[], int n){
    for(int i=0; exp[i] < n; i++){
        
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            
            char popped = pop();
            
            if(popped=='\0' || !isMatchingPair(popped, exp[i])){
                return 0;
            }
        }
    }
    
    if(top == -1)
        return 1;
    else
        return 0;
}

int main(){
    char exp[6] = {'{', '{', '(', ')', '}', '}'};

    if(isBalanced(exp, 6))
        printf("\nBalanced Parentheses\n\n");
    else
        printf("\nNot Balanced\n\n");

    return 0;
}