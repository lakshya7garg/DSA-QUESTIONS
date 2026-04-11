class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto& [val, idx] : pos) {
            for (int i = 0; i + 2 < idx.size(); i++) {
                ans = min(ans, 2 * (idx[i + 2] - idx[i]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};