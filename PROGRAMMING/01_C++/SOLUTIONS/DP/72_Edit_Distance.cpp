#include<iostream>
using namespace std;


// Top-Down

class Solution {
public:
    int n,m;

    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j) {
        if (i == n) return m-j;
        if (j == m) return n-i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(dp, s1, s2, i+1, j+1);
        }
        else {
            int insertChar = 1 + solve(dp, s1, s2, i, j+1);
            int deleteChar = 1 + solve(dp, s1, s2, i+1, j);
            int replaceChar = 1 + solve(dp, s1, s2, i+1, j+1);

            return dp[i][j] = min({insertChar, deleteChar, replaceChar});
        }

        return -1;
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        vector<vector<int>> dp(501, vector<int> (501, -1));

        return solve(dp, word1, word2, 0, 0);
    }
};

// ==================================================================================

// Bottom-Up