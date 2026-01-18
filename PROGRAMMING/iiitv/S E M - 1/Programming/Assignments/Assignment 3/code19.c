#include <stdio.h>

int main () {
    char ch;
    printf ("Enter a character: ");
    scanf ("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') {
        printf ("The character '%c' is Uppercase.\n", ch);
    }
    else if (ch >= 'a' && ch <= 'z') {
        printf ("The character '%c' is Lowercase.\n", ch);
    }
    else {
        printf ("The character '%c' is not an alphabet letter.\n", ch);
    }
    return 0;
}
