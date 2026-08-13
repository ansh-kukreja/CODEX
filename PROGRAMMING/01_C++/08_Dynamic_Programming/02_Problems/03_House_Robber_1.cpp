#include<iostream>
using namespace std;


// ========= Top Down Approach ==========

class Solution {
public:
    
    int solve(vector<int>& nums, int n, vector<int>& dp, int i) {

        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(nums, n, dp, i+2);
        int skip = solve(nums, n, dp, i+1);

        dp[i] = max(steal, skip);

        return dp[i];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(101, -1);

        return solve(nums, n, dp, 0);
    }
};


// ================================================================================================

// ========= Bottom Up Approach ==========

int rob(vector<int>& nums) {
    
    int n = nums.size();
    
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = nums[0];

    for (int i=2; i<=n; i++) {
        int steal = nums[i-1] + dp[i-2];
        int skip = dp[i-1];

        dp[i] = max(steal, skip);
    }

    return dp[n];
}