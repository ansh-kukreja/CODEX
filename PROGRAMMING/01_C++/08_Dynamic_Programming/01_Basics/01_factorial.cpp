#include<iostream>
using namespace std;


// Using Method 1: ( Top-Down ) Recursion + Memoization

int fibo(int n, vector<int> &dp) {
    if (n <= 1) 
        return n;

    if (dp[n] != -1) 
        return dp[n];

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);

    return dp[n];
}


int main(){
    int n;
    cout<<"\nEnter a Number: ";
    cin>>n;

    vector<int> dp(n+1, -1);

    int ans = fibo(n, dp);

    cout<<"\n\nFibonacci Number is "<<ans<<endl<<endl;
}



// ================================================================================================

// Using Method 2: ( Bottom-Up ) Tabulation


int fibo(int n) {
    if (n == 0) return 0;

    vector<int> dp(n+1, -1);

    dp[0] = 0;
    dp[1] = 1;
    
    for (int i=2; i<=n; i++) 
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}




// ================================================================================================

// Space Optimisation

int fibo(int n) {
    if (n == 0) return 0;

    int prev2 = 0;
    int prev1 = 1;
    
    for (int i=2; i<=n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}