#include <stdio.h>
#include <windows.h>

int turn = 0;

void process0() {
    for (int i = 0; i < 5; i++) {
        while (turn != 0);

        printf("Process P0 in Critical Section (iteration %d)\n", i + 1);
        Sleep(1000);

        turn = 1;
        printf("Process P0 in Remainder Section\n");
        Sleep(1000);
    }
}

void process1() {
    for (int i = 0; i < 5; i++) {
        while (turn != 1);

        printf("Process P1 in Critical Section (iteration %d)\n", i + 1);
        Sleep(1000);

        turn = 0;
        printf("Process P1 in Remainder Section\n");
        Sleep(1000);
    }
}

int main() {
    printf("Simulating Strict Alternation Algorithm\n\n");

    for (int i = 0; i < 5; i++) {
        process0();
        process1();
    }

    printf("\nSimulation complete.\n");
    return 0;
}
