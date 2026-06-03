#include <stdio.h>

int main() {
    char text[200];
    int freq[256], i = 0;

    for (i = 0; i < 256; i++) freq[i] = 0;

    printf("Enter a string: ");
    scanf("%s", text);

    i = 0;
    while (text[i] != '\0') {
        freq[(unsigned char)text[i]]++;
        i++;
    }

    i = 0;
    while (i < 256) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
        i++;
    }

    return 0;
}
