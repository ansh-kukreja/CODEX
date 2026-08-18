#include <stdio.h>

int main () {
    int marks[3];
    int i;
    printf ("Enter Marks of Students:\n");
    for (i = 0; i < 3; i++) {
        printf ("Student %d: ", i + 1);
        scanf ("%d", &marks[i]);
    }
    printf ("Marks of Students:\n");
    for (i = 0; i < 3; i++) {
        printf ("Student %d: %d\n", i + 1, marks[i]);
    }
    return 0;
}
