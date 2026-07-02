class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<tuple<int,int,int>> q;
        q.push({0, 0, health - grid[0][0]});
        best[0][0] = health - grid[0][0];

        if (best[0][0] <= 0) return false;

        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1 && h > 0) return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                int nh = h - grid[nr][nc];

                if (nh <= 0) continue;

                if (nh > best[nr][nc]) {
                    best[nr][nc] = nh;
                    q.push({nr, nc, nh});
                }
            }
        }

        return false;
    }
};