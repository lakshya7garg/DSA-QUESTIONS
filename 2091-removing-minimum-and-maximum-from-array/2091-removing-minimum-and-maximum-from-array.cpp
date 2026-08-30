class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();

        if (mn > mx) swap(mn, mx);

        int ans = mx + 1;
        ans = min(ans, n - mn);

        ans = min(ans, mn + 1 + n - mx);

        return ans;
    }
};