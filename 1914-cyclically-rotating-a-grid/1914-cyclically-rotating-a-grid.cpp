class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> nums;

            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;

            // left column: top to bottom
            for (int i = top; i <= bottom; i++) {
                nums.push_back(grid[i][left]);
            }

            // bottom row: left + 1 to right
            for (int j = left + 1; j <= right; j++) {
                nums.push_back(grid[bottom][j]);
            }

            // right column: bottom - 1 to top
            for (int i = bottom - 1; i >= top; i--) {
                nums.push_back(grid[i][right]);
            }

            // top row: right - 1 to left + 1
            for (int j = right - 1; j > left; j--) {
                nums.push_back(grid[top][j]);
            }

            int len = nums.size();
            int shift = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = nums[(i + shift) % len];
            }

            int idx = 0;

            // put back in same traversal order
            for (int i = top; i <= bottom; i++) {
                grid[i][left] = rotated[idx++];
            }

            for (int j = left + 1; j <= right; j++) {
                grid[bottom][j] = rotated[idx++];
            }

            for (int i = bottom - 1; i >= top; i--) {
                grid[i][right] = rotated[idx++];
            }

            for (int j = right - 1; j > left; j--) {
                grid[top][j] = rotated[idx++];
            }
        }

        return grid;
    }
};