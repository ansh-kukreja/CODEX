#include <stdio.h>

int main () {
    int num, temp, result = 0, reminder;
    printf ("Enter a Number: ");
    scanf ("%d", &num);
    temp = num;
    while (temp != 0) {
        reminder = temp % 10;
        result = result * 10 + reminder;
        temp /= 10;
    }
    if (result == num) {
        printf ("%d is a Palindrome number\n", num);
    } else {
        printf ("%d is not a Palindrome number\n", num);
    }
    return 0;
}
