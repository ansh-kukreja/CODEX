#include <stdio.h>
#include "bill.h"

int main() {
    float basePrice, gstRate, discountPercent, distance;

    printf("\nEnter base price of the dish: ");
    scanf("%f", &basePrice);

    printf("Enter GST rate: ");
    scanf("%f", &gstRate);

    printf("Enter discount percent: ");
    scanf("%f", &discountPercent);

    printf("Enter distance from restaurant in km: ");
    scanf("%f", &distance);

    float finalAmount = calculateFinalAmount(basePrice, gstRate, discountPercent, distance);

    printf("\n--- Bill Summary ---\n");
    printf("Base Price: Rs %.2f\n", basePrice);
    printf("GST Applied: Rs %.2f\n", (basePrice * gstRate) / 100);
    printf("Discount: Rs %.2f\n", ((basePrice + (basePrice * gstRate / 100)) * discountPercent) / 100);
    printf("Delivery Charge: Rs %.2f\n", calculateDeliveryCharge(distance));
    printf("---------------------------\n");
    printf("Final Amount to Pay: Rs %.2f /- \n", finalAmount);

    return 0;
}


//    gcc main.c bill.c -o bill
//    ./bill