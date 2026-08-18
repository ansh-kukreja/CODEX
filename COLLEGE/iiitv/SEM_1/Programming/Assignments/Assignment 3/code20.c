#include <stdio.h>

int main () {
    char ch;
    printf ("Enter a lowercase character: ");
    scanf ("%c", &ch);
    if (ch >= 'a' && ch <= 'z') {
        char upper = 'A' + (ch - 'a');
        printf ("Uppercase of '%c' is '%c'\n", ch, upper);
    }
    else {
        printf ("The character '%c' is not a lowercase character.\n", ch);
    }
    return 0;
}
