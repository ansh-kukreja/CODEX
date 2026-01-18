#include <stdio.h>
#include "stringHeader.h"

int main() {
    char str[100];
    char temp[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    i = 0;
    while (str[i] != '\0') {
        temp[i] = str[i];
        i++;
    }
    temp[i] = '\0';

    reverseString(temp);

    printf("Reversed string: %s\n", temp);

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}



//    gcc main.c stringHeader.c -o program
//    ./program
