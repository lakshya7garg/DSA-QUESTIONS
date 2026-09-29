class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int b, vector<vector<char>>& g) {
        if (b < 0 || b > n + m) return false;

        if (i == n - 1 && j == m - 1)
            return b == 0;

        int &res = dp[i][j][b];
        if (res != -1) return res;

        res = 0;

        if (i + 1 < n) {
            int nb = b + (g[i + 1][j] == '(' ? 1 : -1);
            res |= solve(i + 1, j, nb, g);
        }

        if (j + 1 < m) {
            int nb = b + (g[i][j + 1] == '(' ? 1 : -1);
            res |= solve(i, j + 1, nb, g);
        }

        return res;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false;

        if ((n + m - 1) % 2)
            return false;

        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m, -1)));

        return solve(0, 0, 1, grid);
    }
};