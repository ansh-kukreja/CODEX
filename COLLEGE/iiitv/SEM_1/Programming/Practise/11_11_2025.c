#include <stdio.h>

int isPrime(int num) {
    if (num <= 1)
        return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0; 
    }
    return 1; 
}


int main() {
    int M, N;
    printf("Enter range (M and N): ");
    scanf("%d %d", &M, &N);

    int count = 0;
    for (int i = M; i <= N; i++) {
        if (isPrime(i)){
            count++;
        }
    }
    printf("Count of prime numbers between %d and %d: %d\n", M, N, count);

    return 0;
}
