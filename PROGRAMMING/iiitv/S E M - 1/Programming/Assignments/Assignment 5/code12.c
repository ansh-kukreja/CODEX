#include <stdio.h>

int main() {
    char sentence[100];
    int i = 0, length = 0, maxLen = 0, start = 0, maxStart = 0;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            if (length == 0) start = i;
            length++;
        } else {
            if (length > maxLen) {
                maxLen = length;
                maxStart = start;
            }
            length = 0;
        }
        i++;
    }
    if (length > maxLen) {
        maxLen = length;
        maxStart = start;
    }

    printf("Longest word: ");
    i = 0;
    while (i < maxLen) {
        printf("%c", sentence[maxStart + i]);
        i++;
    }

    return 0;
}
