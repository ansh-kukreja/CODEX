#include "bill.h"

float applyGST(float basePrice, float gstRate) {
    float gstAmount = (basePrice * gstRate) / 100.0;
    return basePrice + gstAmount;
}

float applyDiscount(float price, float discountPercent) {
    float discountAmount = (price * discountPercent) / 100.0;
    return price - discountAmount;
}

float calculateDeliveryCharge(float distance) {
    if (distance <= 2)
        return 20;   
    else if (distance <= 5)
        return 40;   
    else if (distance <= 10)
        return 60;   
    else
        return 100;  
}

float calculateFinalAmount(float basePrice, float gstRate, float discountPercent, float distance) {
    float priceWithGST = applyGST(basePrice, gstRate);
    float priceAfterDiscount = applyDiscount(priceWithGST, discountPercent);
    float deliveryCharge = calculateDeliveryCharge(distance);
    float finalAmount = priceAfterDiscount + deliveryCharge;
    return finalAmount;
}
