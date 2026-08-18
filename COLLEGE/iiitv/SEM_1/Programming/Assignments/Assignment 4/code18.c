#include <stdio.h>

int main() {
    int i = 0;
    char *names[] = {"Ansh", "Gauraansh", "Chris", "Tony", "Natasha"};
    int rolls[] = {1, 2, 3, 4, 5};
    float percs[] = {85.5, 90.3, 75.0, 88.1, 95.7};

    printf("%-15s %-10s %-10s\n", "Name", "Roll No", "Percentage");

    while(i < 5) {
        printf("%-15s %-10d %-10.2f\n", names[i], rolls[i], percs[i]);
        i++;
    }
}
