#include <stdio.h>

int main() {
    char word[40];
    int i = 0, length = 0, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", word);

    while (word[length] != '\0') length++;

    int start = 0, end = length - 1;
    while (start < end) {
        if (word[start] != word[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome)
        printf("String is Palindrome");
    else
        printf("String is Not Palindrome");

    return 0;
}
