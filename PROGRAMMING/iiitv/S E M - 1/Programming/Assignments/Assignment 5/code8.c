#include <stdio.h>

int main() {
    char first[100], second[100];
    int i = 0, j = 0;

    printf("Enter first string: ");
    scanf("%s", &first);
    printf("Enter second string: ");
    scanf("%s", &second);

    while (first[i] != '\0') i++;

    while (second[j] != '\0') {
        first[i] = second[j];
        i++;
        j++;
    }
    first[i] = '\0';

    printf("Concatenated String: %s", first);
    return 0;
}
