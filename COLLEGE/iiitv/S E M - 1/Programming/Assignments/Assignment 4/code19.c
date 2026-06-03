#include <stdio.h>

int main() {
    int i = 0;
    char *items[] = {"Apple", "Banana", "Milk", "Bread"};
    int qty[] = {2, 6, 1, 2};
    float price[] = {100.0, 60.0, 50.0, 40.0};

    printf("%-20s %-10s %-10s\n", "Item", "Qty", "Price");

    while(i < 4) {
        printf("%-20s %-10d %-10.2f\n", items[i], qty[i], price[i]);
        i++;
    }
}
