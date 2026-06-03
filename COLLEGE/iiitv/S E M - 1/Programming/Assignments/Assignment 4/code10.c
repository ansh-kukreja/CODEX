#include <stdio.h>


void decimalToBinary(double num) {
   int intPart = (int)num;      
   double fracPart = num - intPart;
  
   int binaryInt[32], i = 0;
   if (intPart == 0) {
       printf("0");
   } else {
       while (intPart > 0) {
           binaryInt[i++] = intPart % 2;
           intPart /= 2;
       }
       for (int j = i - 1; j >= 0; j--) {
           printf("%d", binaryInt[j]);
       }
   }

    if (fracPart > 0) {
       printf(".");
       for (int k = 0; k < 2; k++) {
           fracPart *= 2;
           int fracBit = (int)fracPart;
           printf("%d", fracBit);
           fracPart -= fracBit;
       }
   }
}


int main() {
   double num;
   printf("Enter a decimal number: ");
   scanf("%lf", &num);


   printf("Binary (upto 2 precision) = ");
   decimalToBinary(num);
}