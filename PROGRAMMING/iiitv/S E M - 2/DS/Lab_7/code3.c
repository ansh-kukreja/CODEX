#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char exp[] = "(A+B)*(C+D)";
    char postfix[MAX];
    int i, k = 0;

    for (i = 0; i < strlen(exp); i++) {
        if (isalnum(exp[i])) {
            postfix[k++] = exp[i];
        }
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(exp[i])) {
                postfix[k++] = pop();
            }
            push(exp[i]);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}