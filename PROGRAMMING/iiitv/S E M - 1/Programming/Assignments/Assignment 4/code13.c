#include <stdio.h>

int main(){
    int d = 12;
    printf("%x", d);
}

// int main() {
//     int num, temp, i = 0;
//     char hex[32], c;

//     printf("Enter decimal number: ");
//     scanf("%d", &num);

//     temp = num;
//     while(temp > 0) {
//         int rem = temp % 16;
//         if(rem < 10) c = rem + '0';
//         else c = rem - 10 + 'A';
//         hex[i] = c;
//         i = i + 1;
//         temp = temp / 16;
//     }

//     printf("Hexadecimal: ");
//     while(i > 0) {
//         i = i - 1;
//         printf("%c", hex[i]);
//     }
// }
