#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[] = "23*54*+9-";
    int i, a, b, result;

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    result = pop();
    printf("Result: %d\n", result);

    return 0;
}