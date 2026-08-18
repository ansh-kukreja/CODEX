#include <stdio.h>

void countVowels(char input[]) {
    static int vowelCount = 0;
    int i = 0;

    while (input[i] != '\0') {
        char ch = input[i];
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
        i++;
    }

    printf("Total vowels till now: %d\n", vowelCount);

    if (vowelCount > 10) {
        printf("ALERT: Vowel count exceeded 10!\n");
    }
}

int main() {
    char str[100];

    printf("Enter strings (type 'exit' to exit)\n");

    while(1){
        printf("Input: ");
        scanf("%s", str);

        if (strcmp(str, "exit") == 0){
            break;
        }

        countVowels(str);
    }

    return 0;
}
