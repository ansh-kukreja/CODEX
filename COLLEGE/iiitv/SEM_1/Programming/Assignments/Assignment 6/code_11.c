#include <stdio.h>

int main() {
    int bufferSize = 2;
    int buffer[bufferSize];
    int count = 0;          
    int totalLost = 0;   
    int index = 0;          
    int newValue;

    printf("\n--Enter integers (enter -1 to stop)--\n");

    while (1) {
        printf("Enter value: ");
        scanf("%d", &newValue);

        if (newValue == -1)
            break;

        if (count < bufferSize) {
            buffer[index] = newValue;
            count++;
        } 
        else {
            int lostValue = buffer[index];
            buffer[index] = newValue;
            totalLost++;
            printf("Lost value: %d , Total lost data: %d\n", lostValue, totalLost);
        }

        index = (index + 1) % bufferSize;

        printf("Current buffer: ");
        for (int i = 0; i < count; i++){
            printf("%d ", buffer[i]);
        }

        printf("\n\n");
    }

    return 0;
}
