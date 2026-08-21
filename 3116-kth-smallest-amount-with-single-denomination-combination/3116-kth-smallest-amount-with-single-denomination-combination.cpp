class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto gcd = [](long long a, long long b) {
            while (b) {
                long long t = a % b;
                a = b;
                b = t;
            }
            return a;
        };

        auto lcm = [&](long long a, long long b) {
            return a / gcd(a, b) * b;
        };

        // Count how many valid amounts are <= x
        auto count = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long L = 1;
                int bits = 0;
                bool tooLarge = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        L = lcm(L, coins[i]);

                        if (L > x) {
                            tooLarge = true;
                            break;
                        }
                    }
                }

                if (tooLarge)
                    continue;

                if (bits & 1)
                    ans += x / L;
                else
                    ans -= x / L;
            }

            return ans;
        };

        // The kth answer cannot exceed k * minimum coin.
        long long lo = 1;
        long long hi = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};