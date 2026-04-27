class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: up, right, down, left
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // For each street type, allowed directions
        vector<vector<int>> dirs = {
            {},          // 0 unused
            {1, 3},      // type 1: left, right
            {0, 2},      // type 2: up, down
            {3, 2},      // type 3: left, down
            {1, 2},      // type 4: right, down
            {3, 0},      // type 5: left, up
            {1, 0}       // type 6: right, up
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) {
                return true;
            }

            int type = grid[r][c];

            for (int dir : dirs[type]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                    continue;
                }

                if (visited[nr][nc]) {
                    continue;
                }

                int nextType = grid[nr][nc];

                // Opposite direction must exist in neighbor cell
                int opposite = (dir + 2) % 4;

                bool connected = false;
                for (int nextDir : dirs[nextType]) {
                    if (nextDir == opposite) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};