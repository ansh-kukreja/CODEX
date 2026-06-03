#include <stdio.h>

int main () {
    int num1, num2, num3, greatest=0;
    printf ("Enter 3 Numbers:\n");
    scanf ("%d %d %d", &num1, &num2, &num3);
    if (num1>=num2 && num1>=num3 && (num1!=num2 || num1!=num3)) {
        greatest=num1;
    }
    if (num2>=num1 && num2>=num3 && (num2!=num1 || num2!=num3)) {
        greatest=num2;
    }
    if (num3>=num1 && num3>=num2 && (num3!=num1 || num3!=num2)) {
        greatest=num3;
    }
    if (greatest==0) {
        printf ("All numbers are Equal");
    }
    else {
        printf ("%d is Greatest", greatest);
    }
    return 0;
}