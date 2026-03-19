class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();

        //prefix sum arrays
        vector<vector<int>> X(m+1, vector<int>(n+1,0));
        vector<vector<int>> Y(m+1, vector<int>(n+1,0));

        int ans=0;

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {

                //build prefix sum
                X[i][j]= X[i-1][j] + X[i][j-1] - X[i-1][j-1];
                Y[i][j]= Y[i-1][j] + Y[i][j-1] - Y[i-1][j-1];

                if (grid[i-1][j-1] == 'X') X[i][j]++;
                if (grid[i-1][j-1] == 'Y') Y[i][j]++;

                //check condition
                if (X[i][j] > 0 && X[i][j] == Y[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};