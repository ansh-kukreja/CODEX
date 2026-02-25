class Solution {
public:
    bool isPrime(int n){
        int setBits = 0;

        while(n > 0){
            int bit = n&1;
            if(bit) setBits++;
            n = n >> 1;
        }

        if(setBits == 1) return false;
        
        for(int i = 2; i<setBits; i++){
            if(setBits % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int primes = 0;

        for(int i=left; i<= right; i++){
            if(isPrime(i)) primes++;
        }

        return primes;
    }
};