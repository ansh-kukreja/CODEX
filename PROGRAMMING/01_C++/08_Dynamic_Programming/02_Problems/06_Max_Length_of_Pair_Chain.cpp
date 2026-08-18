#include<iostream>
using namespace std;


// Top-Down

class Solution {
public:
    int n;

    int solve (vector<vector<int>>& dp, vector<vector<int>>& nums, int i, int prevPeak) {
        if (i >= n) return 0;

        if (prevPeak != -1 && dp[i][prevPeak] != -1) 
            return dp[i][prevPeak];


        // Taking (if possible)
        int take = INT_MIN;

        if (prevPeak == -1 || nums[prevPeak][1] < nums[i][0]) {
            take = 1 + solve(dp, nums, i+1, i);
        }

        // Skiping
        int skip = solve(dp, nums, i+1, prevPeak);


        // Edge-case check
        if (prevPeak != -1) 
            dp[i][prevPeak] = max(take, skip);

        return max(take, skip);
    }


    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();

        sort(begin(pairs), end(pairs));

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(dp, pairs, 0, -1);
    }
};


// ==========================================================================================

// Bottom-Up

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(begin(pairs), end(pairs));

        vector<int> dp(n+1, 1);
        int ans = 1;

        for (int i=0; i<n; i++) {

            for (int j=0; j<i; j++) {

                if (pairs[j][1] < pairs[i][0]) {

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