class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries){
        vector<int> digits, pos;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        vector<long long> p10(m + 1, 1), prefNum(m + 1, 0);
        vector<int> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            p10[i + 1] = (p10[i] * 10) % MOD;
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long num = (prefNum[R + 1] -
                             prefNum[L] * p10[len] % MOD +
                             MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};