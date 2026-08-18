#include<iostream>
using namespace std;


// Top-Down

class Solution {
public:
    int n;

    static bool comparator(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    bool isSubsequence(string &s, string &t) {
        int n = s.size();
        int m = t.size();

        if (n >= m || m-n != 1) return false;

        int i = 0;
        int j = 0;

        while (i < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                j++;

                if (j >= m) return false;
            }
        }

        return true;
    }

    int lis (vector<vector<int>>& dp, vector<string>& words, int i, int prevPeak) {
        if (i >= n) return 0;

        if (prevPeak != -1 && dp[i][prevPeak] != -1) 
            return dp[i][prevPeak];


        // Taking (if possible)
        int take = INT_MIN;

        if ( prevPeak == -1 || isSubsequence( words[prevPeak], words[i] ) ) {
            take = 1 + lis(dp, words, i+1, i);
        }

        // Skiping
        int skip = lis(dp, words, i+1, prevPeak);


        // Edge-case check
        if (prevPeak != -1) 
            dp[i][prevPeak] = max(take, skip);

        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();

        sort(begin(words), end(words), comparator);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return lis(dp, words, 0, -1);
    }
};


// ===============================================================================================

// Bottom-Up

class Solution {
public:
    int n;

    static bool comparator(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    bool isSubsequence(string &s, string &t) {
        int n = s.size();
        int m = t.size();

        if (n >= m || m-n != 1) return false;

        int i = 0;
        int j = 0;

        while (i < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                j++;

                if (j >= m) return false;
            }
        }

        return true;
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();

        sort(begin(words), end(words), comparator);
        
        vector<int> dp(n+1, 1);
        int ans = 1;

        for (int i=0; i<n; i++) {

            for (int j=0; j<i; j++) {

                if (isSubsequence(words[j], words[i])) {

                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};