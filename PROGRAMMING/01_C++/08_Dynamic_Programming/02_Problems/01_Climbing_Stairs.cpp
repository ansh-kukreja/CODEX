#include<iostream>
using namespace std;



// ==== Top Down Approach (Recursion + Memo) ====

class Solution {
public:

    int solve(int n, vector<int>& dp) {
        if (n < 0) return 0;

        if (n == 0) return 1;

        if (dp[n] != -1) return dp[n];

        int ways = solve(n-1, dp) + solve(n-2, dp);
        dp[n] = ways;

        return ways;
    }


    int climbStairs(int n) {

        vector<int> dp(n+1, -1);

        return solve(n, dp);
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