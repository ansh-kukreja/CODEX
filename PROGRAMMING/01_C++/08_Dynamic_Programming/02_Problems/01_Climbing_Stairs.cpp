#include<iostream>
using namespace std;



// ==== Top Down Approach (Recursion + Memo) ====

class Solution {
public:

    int solve(int i, int n, vector<int>& dp) {
        if (i == n) 
            return 1;

        if (i > n)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = solve(i+1, n, dp) + solve(i+2, n, dp);
    }


    int climbStairs(int n) {

        vector<int> dp(n+1, -1);

        return solve(0, n, dp);
    }
};




// ================================================================================================

// ==== Bottom Up Approach (Tabulation) ====


int climbStairs(int n) {
    if (n == 1 || n == 2) return n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}