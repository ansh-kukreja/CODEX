#include <stdio.h>

int main() {
    char text[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", text);

    while (text[i] != '\0') {
        if (text[i] != ' ') {
            text[j] = text[i];
            j++;
        }
        i++;
    }
    text[j] = '\0';

    printf("String without spaces: %s", text);
    return 0;
}
