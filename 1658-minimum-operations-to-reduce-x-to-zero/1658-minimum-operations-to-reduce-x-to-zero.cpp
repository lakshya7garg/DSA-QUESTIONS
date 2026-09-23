class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        for (int a : nums) sum += a;

        int target = sum - x;
        if (target < 0) return -1;
        if (target == 0) return n;

        int l = 0, cur = 0, best = -1;

        for (int r = 0; r < n; r++) {
            cur += nums[r];

            while (cur > target && l <= r)
                cur -= nums[l++];

            if (cur == target)
                best = max(best, r - l + 1);
        }

        return best == -1 ? -1 : n - best;
    }
};