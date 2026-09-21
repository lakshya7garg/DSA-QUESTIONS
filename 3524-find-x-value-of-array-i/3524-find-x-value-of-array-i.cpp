class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);

        for (int num : nums) {
            vector<long long> ndp(k);

            int x = num % k;

            // Subarray containing only num
            ndp[x]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                ndp[(r * x) % k] += dp[r];
            }

            // Add all subarrays ending here
            for (int r = 0; r < k; r++)
                ans[r] += ndp[r];

            dp = ndp;
        }

        return ans;
    }
};