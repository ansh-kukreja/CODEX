#include <stdio.h>

void demo() {
    int localVar = 0;
    static int staticVar = 0;
    localVar++;
    staticVar++;
    printf("Local: %d, Static: %d\n", localVar, staticVar);
}

int main() {
    int i = 0;
    while(i < 5) {
        demo();
        i++;
    }
}