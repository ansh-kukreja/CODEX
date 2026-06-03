#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    int i = 0, alphabets = 0, words = 0, digits = 0, spaces = 0, specialChars = 0;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    while (sentence[i] != '\0') {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            alphabets++;
        }
        else if (sentence[i] >= '0' && sentence[i] <= '9') {
            digits++;
        } 
        else if (sentence[i] == ' ') {
            spaces++;
        } 
        else {
            specialChars++;
        }
        i++;
    }

    if (i > 0 && (digits > 0 || alphabets > 0 || specialChars > 0)){
        words = spaces + 1;
    }

    printf("Words: %d\nDigits: %d\nSpaces: %d\nSpecial Characters: %d\n", words, digits, spaces, specialChars);

    return 0;
}
