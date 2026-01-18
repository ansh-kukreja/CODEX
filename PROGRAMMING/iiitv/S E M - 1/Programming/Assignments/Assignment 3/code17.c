#include <stdio.h>

int main () {
    char str [50];
    printf ("Enter a String: \n");
    fgets (str, sizeof (str), stdin);
    printf ("You Have Entered: %s", str);
    return 0;
}
