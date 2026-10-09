#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    int tsp(vector<vector<int>>& cost) {

        int n = cost.size();

        int totalMasks = 1 << n;

        vector<vector<int>> dp(
            totalMasks,
            vector<int>(n, INT_MAX)
        );

        dp[1][0] = 0;

        for (int mask = 1; mask < totalMasks; mask++) {

            for (int city = 0; city < n; city++) {

                if (!(mask & (1 << city)))
                    continue;

                if (dp[mask][city] == INT_MAX)
                    continue;

                for (int next = 0; next < n; next++) {

                    if (mask & (1 << next))
                        continue;

                    int newMask = mask | (1 << next);

                    dp[newMask][next] = min(
                        dp[newMask][next],
                        dp[mask][city] + cost[city][next]
                    );
                }
            }
        }

        int allVisited = totalMasks - 1;

        int answer = INT_MAX;

        for (int city = 0; city < n; city++) {

            answer = min(
                answer,
                dp[allVisited][city] + cost[city][0]
            );
        }

        return answer;
    }
};


int main() {

    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    Solution obj;

    int answer = obj.tsp(cost);

    cout << "Minimum cost of travelling: "
         << answer << endl;

    return 0;
}