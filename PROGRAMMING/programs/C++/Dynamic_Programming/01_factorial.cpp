#include<iostream>
using namespace std;


// Using Method 1: Recursion + Memoization

int fibonacci(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n];
}

int main(){
    int n;
    cout<<"\nEnter a Number: ";
    cin>>n;

    vector<int> dp(n+1);

    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }

    int ans = fibonacci(n, dp);

    cout<<endl<<n<<"th Fibonacci Number is "<<ans<<endl<<endl;
}