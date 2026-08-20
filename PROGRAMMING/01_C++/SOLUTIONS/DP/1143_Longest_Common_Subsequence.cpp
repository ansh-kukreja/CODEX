#include<iostream>
using namespace std;


// Top-Down

class Solution {
public:
    int n,m;

    int solve(vector<vector<int>>& dp, string &text1, string &text2, int i, int j) {
        if ( i >= n || j >= m ) return 0;

        if ( dp[i][j] != -1) return dp[i][j];


        if ( text1[i] == text2[j] ) {
            dp[i][j] = 1 + solve(dp, text1, text2, i+1, j+1);
            return dp[i][j];
        }
        else {
            dp[i][j] = max( 
                solve(dp, text1, text2, i+1, j) ,
                solve(dp, text1, text2, i, j+1) 
            );

            return dp[i][j];
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        vector<vector<int>> dp(1001, vector<int> (1001, -1));
        
        return solve(dp, text1, text2, 0, 0);
    }
};


// ==================================================================================================

// Bottom-Up

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));

        for (int row=0; row <= n; row++) {
            dp[row][0] = 0;
        }

        for (int col=0; col <= m; col++) {
            dp[0][col] = 0;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(
                        dp[i][j-1],
                        dp[i-1][j]
                    );
                }
            }
        }

        return dp[n][m];
    }
};