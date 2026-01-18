#include <stdio.h>

void acceptCoins() {
    int billAmount  = 275;
    int total_coins = 0;
    int total_value = 0;
    int remaining = billAmount;
    int coin;

    printf("\n-- Bill amount is %d --\n", billAmount);
    printf("Available coin denominations 1, 2, 5, 10\n");

    while (remaining > 0) {
        printf("\nEnter coin: ");
        scanf("%d", &coin);

        if (coin != 1 && coin != 2 && coin != 5 && coin != 10) {
            printf("Invalid coin! Please insert 1, 2, 5, 10 coins only.\n");
            continue;
        }

        total_coins++;
        total_value += coin;
        remaining = billAmount - total_value;

        if (remaining > 0){
            printf("Total coins inserted: %d, Total value: %d, Remaining: %d\n",total_coins, total_value, remaining);
        }
            
        else if (remaining == 0){
            printf("\nPayment complete! Total coins: %d\n",total_coins);
        }
            
        else{
            printf("\nOverpaid by %d Rs Returning change..\nTotal coins: %d, Total value: %d\n",-remaining, total_coins, total_value);
        }
            
    }
}

int main() {
    acceptCoins();
    return 0;
}
