class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = 2 * n;
        
        vector<int> d(m, m);
        unordered_map<int, int> last;
        
        for (int i = 0; i < m; i++) {
            int x = nums[i % n];
            if (last.count(x)) d[i] = min(d[i], i - last[x]);
            last[x] = i;
        }
        
        last.clear();
        for (int i = m - 1; i >= 0; i--) {
            int x = nums[i % n];
            if (last.count(x)) d[i] = min(d[i], last[x] - i);
            last[x] = i;
        }
        
        for (int i = 0; i < n; i++) {
            d[i] = min(d[i], d[i + n]);
        }
        
        vector<int> ans;
        for (int idx : queries) {
            ans.push_back(d[idx] >= n ? -1 : d[idx]);
        }
        return ans;
    }
};