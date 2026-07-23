class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // Store each diagonal
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Sort in descending order
        for (auto &x : mp) {
            sort(x.second.begin(), x.second.end(), greater<int>());
        }

        // Fill back in ascending order
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return mat;
    }
};