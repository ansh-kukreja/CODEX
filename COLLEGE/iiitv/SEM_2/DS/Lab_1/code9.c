#include<stdio.h>

int main(){
    int price;
    float discount = 18.9;

    printf("Enter the Price: ");
    scanf("%d", &price);

    float discountAmount = ((float)price / 100) * discount;
    float discountedPrice = (float)price - discountAmount;

    printf("Discounted Price: %.2f\n\n", discountedPrice);
}