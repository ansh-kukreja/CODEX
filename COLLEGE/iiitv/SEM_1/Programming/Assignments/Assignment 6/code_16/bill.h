#ifndef BILL_H
#define BILL_H

float applyGST(float basePrice, float gstRate);
float applyDiscount(float price, float discountPercent);
float calculateDeliveryCharge(float distance);
float calculateFinalAmount(float basePrice, float gstRate, float discountPercent, float distance);

#endif
