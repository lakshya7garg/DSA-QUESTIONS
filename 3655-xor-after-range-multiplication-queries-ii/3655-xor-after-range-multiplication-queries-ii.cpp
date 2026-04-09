class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long modPow(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        // cache inverse only for used values
        unordered_map<int, long long> invCache;
        auto getInv = [&](int x) -> long long {
            auto it = invCache.find(x);
            if (it != invCache.end()) return it->second;
            long long inv = modPow(x, MOD - 2);
            invCache[x] = inv;
            return inv;
        };

        // small[k][rem] stores {L, R, v} on compressed sequence
        vector<vector<vector<array<int, 3>>>> small(B + 1);
        for (int k = 1; k <= B; k++) {
            small[k].resize(k);
        }

        // process large k directly, store small k
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                int rem = l % k;
                int L = (l - rem) / k;
                int R = (r - rem) / k;
                small[k][rem].push_back({L, R, v});
            }
        }

        // process all small k
        for (int k = 1; k <= B; k++) {
            for (int rem = 0; rem < k; rem++) {
                if (rem >= n) continue;

                int len = (n - 1 - rem) / k + 1;
                vector<long long> diff(len + 1, 1);

                for (auto &seg : small[k][rem]) {
                    int L = seg[0], R = seg[1], v = seg[2];
                    diff[L] = (diff[L] * v) % MOD;
                    if (R + 1 < len) {
                        diff[R + 1] = (diff[R + 1] * getInv(v)) % MOD;
                    }
                }

                long long cur = 1;
                for (int t = 0; t < len; t++) {
                    cur = (cur * diff[t]) % MOD;
                    int idx = rem + t * k;
                    nums[idx] = (1LL * nums[idx] * cur) % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};