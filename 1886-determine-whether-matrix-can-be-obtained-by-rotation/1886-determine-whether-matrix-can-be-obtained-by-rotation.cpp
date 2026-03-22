class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        
        for (int rot=0; rot<4; rot++) {
            if (mat==target) return true;
            
            vector<vector<int>> temp(n, vector<int>(n));
            
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    temp[j][n-1-i] = mat[i][j];
                }
            }
            mat = temp;
        }
        
        return false;
    }
};