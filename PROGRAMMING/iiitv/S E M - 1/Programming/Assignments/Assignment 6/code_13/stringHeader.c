#include "stringHeader.h"

void reverseString(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int i = 0;
    int j = len - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}


int isPalindrome(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (str[i] != str[j]){
            return 0;
        }  
        i++;
        j--;
    }
    return 1;
}
