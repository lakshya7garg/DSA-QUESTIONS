class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = {robots[i], distance[i]};
        }
        
        // sort robots and walls
        ranges::sort(arr, {}, &pair<int,int>::first);
        ranges::sort(walls);
        
        // memo table
        vector f(n, vector<int>(2,-1));
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if(i<0) return 0;
            if(f[i][j]!=-1) return f[i][j];
            
            // fire left
            int left = arr[i].first - arr[i].second;
            if(i>0) left = max(left, arr[i-1].first+1); // blocked by prev robot
            
            int l = ranges::lower_bound(walls, left) - walls.begin();
            int r = ranges::lower_bound(walls, arr[i].first+1) - walls.begin();
            int ans = dfs(i-1, 0) + (r-l);
            
            // fire right
            int right = arr[i].first + arr[i].second;
            if(i+1<n) {
                if(j==0) right = min(right, arr[i+1].first - arr[i+1].second - 1); // next fired left
                else right = min(right, arr[i+1].first - 1); // blocked at next robot
            }
            
            l = ranges::lower_bound(walls, arr[i].first) - walls.begin();
            r = ranges::lower_bound(walls, right+1) - walls.begin();
            ans = max(ans, dfs(i-1, 1) + (r-l));
            
            return f[i][j] = ans;
        };
        
        return dfs(n-1, 1);
    }
};