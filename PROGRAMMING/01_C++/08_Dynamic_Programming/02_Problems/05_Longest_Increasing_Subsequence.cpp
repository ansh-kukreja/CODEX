#include<iostream>
using namespace std;


// Basic Recursion

class Solution {
public:

    int solve (vector<int>& nums, int n, int i, int prevPeak) {
        if (i >= n) return 0;

        int take = INT_MIN;

        if (prevPeak == -1 || nums[prevPeak] < nums[i]) {
            take = 1 + solve(nums, n, i+1, i);
        }

        int skip = solve(nums, n, i+1, prevPeak);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return solve(nums, n, 0, -1);
    }
};


// ==============================================================================================

// Top-Down

class Solution {
public:
    int n;

    int solve (vector<vector<int>>& dp, vector<int>& nums, int i, int prevPeak) {
        if (i >= n) return 0;

        if (prevPeak != -1 && dp[i][prevPeak] != -1) 
            return dp[i][prevPeak];


        // Taking (if possible)
        int take = INT_MIN;

        if (prevPeak == -1 || nums[prevPeak] < nums[i]) {
            take = 1 + solve(dp, nums, i+1, i);
        }

        // Skiping
        int skip = solve(dp, nums, i+1, prevPeak);


        // Edge-case check
        if (prevPeak != -1) 
            dp[i][prevPeak] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(dp, nums, 0, -1);
    }
};


// ==============================================================================================

// Bottom-Up

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1, 1);
        int ans = 1;

        for (int i=0; i<n; i++) {

            for (int j=0; j<i; j++) {

                if (nums[j] < nums[i]) {

                    if ( (dp[j] + 1) > dp[i] ) {
                        
                        dp[i] = dp[j] + 1;
                        ans = max(ans, dp[i]);
                    }
                }
            }
        }

        return ans;
    }
};