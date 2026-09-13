class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        map<pair<int,int>, int> mp;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(img1[i][j])
                    for(int x = 0; x < n; x++)
                        for(int y = 0; y < n; y++)
                            if(img2[x][y])
                                ans = max(ans, ++mp[{i-x, j-y}]);

        return ans;
    }
};