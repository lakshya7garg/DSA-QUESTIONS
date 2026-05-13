class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int x = min(a, b);
            int y = max(a, b);

            // Initially assume 2 moves for every sum
            diff[2] += 2;

            // 1 move range starts
            diff[x + 1] -= 1;

            // 0 move at x+y
            diff[x + y] -= 1;

            // back to 1 move
            diff[x + y + 1] += 1;

            // back to 2 moves
            diff[y + limit + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};