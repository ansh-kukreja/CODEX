#include<iostream>
using namespace std;


// Normal Recursion

class Solution {
public:
    typedef long long ll;
    int n;

    ll solve(vector<int>& nums, bool flag, int idx) {

        if (idx >= n) return 0;

        ll skip = solve(nums, flag, idx+1);


        ll val = nums[idx];
        if (!flag) val = -val;


        ll take = solve(nums, !flag, idx+1) + val;

        return max(skip, take);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        return solve(nums, true, 0);
    }
};


// ================================================================================================

// Top-Down (Rec + Memo)

class Solution {
public:

    typedef long long ll;
    int n;
    ll t[1000001][2];

    ll solve(int idx, vector<int>& nums, bool flag) {

        if (idx >= n) return 0;

        if (t[idx][flag] != -1) return t[idx][flag];


        ll skip = solve(idx+1, nums, flag);


        ll val = nums[idx];
        if (!flag) val = -val;
        

        ll take = solve(idx+1, nums, !flag) + val;
        t[idx][flag] = max(skip, take);

        return max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(0, nums, true);
    }
};


// ================================================================================================

// Bottom-Up (Tabulation)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector< vector<long> > dp(n+1, vector<long> (2,0));


        for (int i=1; i<=n; i++) {

            // Even Length
            dp[i][1] =  max(
                            dp[i-1][0] - nums[i-1],  // Take
                            dp[i-1][1]               // Skip
                        );

            // Odd Length
            dp[i][0] =  max(
                            dp[i-1][1] + nums[i-1],  // Take
                            dp[i-1][0]               // Skip
                        );
        }

        return max(
                    dp[n][1], 
                    dp[n][0]
                );
    }
};