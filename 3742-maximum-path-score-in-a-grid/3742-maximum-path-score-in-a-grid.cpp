class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int cost = 0; cost <= k; cost++) {
                    if (dp[i][j][cost] == -1) continue;

                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int newCost = cost + (val > 0);
                        if (newCost <= k) {
                            dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost],
                                                        dp[i][j][cost] + val);
                        }
                    }

                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int newCost = cost + (val > 0);
                        if (newCost <= k) {
                            dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost],
                                                        dp[i][j][cost] + val);
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int cost = 0; cost <= k; cost++) {
            ans = max(ans, dp[m - 1][n - 1][cost]);
        }

        return ans;
    }
};