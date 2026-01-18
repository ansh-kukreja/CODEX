#include<stdio.h>

int isPrime(int n){
    int isPrime = 1;

    for(int i=2; i<n; i++){
        if(n % i == 0){
            isPrime = 0;
        }
    }

    return isPrime;
}

int sumOfPrimes(int size, int* arr){
    int sum = 0;

    for(int i=0; i<size; i++){
        if(isPrime(arr[i])){
            sum += arr[i];
        }
    }

    return sum;
}

int main(){
    int arr[7] = { 4 , 7 , 5 , 9 , 54 , 97 , 81 };
    int size = 7;

    printf("Sum of Prime Numbers: %d", sumOfPrimes(size, arr));
    
}