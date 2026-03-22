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
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void reverse(char exp[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

int main() {
    char infix[] = "A+B*C";
    char postfix[MAX], prefix[MAX];
    int i, k = 0;

    reverse(infix);

    for (i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    reverse(postfix);
    strcpy(prefix, postfix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}