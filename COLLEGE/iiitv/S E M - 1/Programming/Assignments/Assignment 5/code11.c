#include <stdio.h>

int main() {
    char text[100], sub[20];
    int i = 0, j, k, count = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", text);
    printf("Enter a substring: ");
    scanf(" %[^\n]", sub);

    while (text[i] != '\0') {
        j = i;
        k = 0;
        while (text[j] != '\0' && sub[k] != '\0' && text[j] == sub[k]) {
            j++;
            k++;
        }
        if (sub[k] == '\0') count++;
        i++;
    }

    printf("Substring occurs %d times", count);
    return 0;
}
