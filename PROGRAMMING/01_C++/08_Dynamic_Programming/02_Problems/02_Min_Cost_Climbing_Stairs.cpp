#include<iostream>
using namespace std;


//  DRY RUN KAR BRO

// Top-Down Approach : Basic Recursion

int solve(vector<int>& cost, int n){
    
    if(n == 0) return cost[0];

    if(n == 1) return cost[1];


    int ans = cost[n] + min( solve(cost, n-1), solve(cost, n-2) );

    return ans;
}


int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    int ans = min(
        solve(cost, n-1), 
        solve(cost, n-2)
    );

    return ans;
}




// ================================================================================================

// Top-Down Approach : Recursion + Memoization

int solve(vector<int>& cost, int n, vector<int>& dp){
    if(n == 0) return cost[0];

    if(n == 1) return cost[1];

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));

    return dp[n];
}


int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    vector<int> dp(n+1, -1);
    int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return ans;
}





// ================================================================================================

// Bottom-up Approach : Tabulation

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    vector<int> dp(n, -1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i=2; i<n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}