//not attempted by me , copy pasted , for the sake of streak , pretty hard

class Solution {
public:
    map<int, map<int,int>> f = {
        {0, {}},
        {1, {}},
        {2, {{2,1}}},
        {3, {{3,1}}},
        {4, {{2,2}}},
        {5, {{5,1}}},
        {6, {{2,1},{3,1}}},
        {7, {{7,1}}},
        {8, {{2,3}}},
        {9, {{3,2}}}
    };

    map<int,int> factorize(long long t) {
        map<int,int> cnt{{2,0},{3,0},{5,0},{7,0}};
        for (int p : {2,3,5,7}) {
            while (t % p == 0) {
                t /= p;
                cnt[p]++;
            }
        }
        if (t != 1) cnt[-1] = 1;
        return cnt;
    }

    map<int,int> getFactors(const map<int,int>& c) {
        int c8 = c.at(2) / 3;
        int r2 = c.at(2) % 3;

        int c9 = c.at(3) / 2;
        int r3 = c.at(3) % 2;

        int c4 = r2 / 2;
        int c2 = r2 % 2;

        int c6 = 0;

        if (c2 && r3) {
            c2 = 0;
            r3 = 0;
            c6 = 1;
        }

        if (r3 && c4) {
            c2 = 1;
            c6 = 1;
            r3 = 0;
            c4 = 0;
        }

        return {
            {2,c2},
            {3,r3},
            {4,c4},
            {5,c.at(5)},
            {6,c6},
            {7,c.at(7)},
            {8,c8},
            {9,c9}
        };
    }

    map<int,int> getFactors(string s) {
        map<int,int> cnt{{2,0},{3,0},{5,0},{7,0}};

        for (char ch : s) {
            for (auto [p,x] : f[ch-'0'])
                cnt[p] += x;
        }

        return cnt;
    }

    map<int,int> subtract(map<int,int> a, map<int,int> b) {
        for (auto [p,x] : b)
            a[p] = max(0, a[p] - x);
        return a;
    }

    int sum(map<int,int> m) {
        int ans = 0;
        for (auto [x,y] : m)
            ans += y;
        return ans;
    }

    string construct(map<int,int> cnt) {
        string ans;

        for (int d = 2; d <= 9; d++)
            ans += string(cnt[d], char('0' + d));

        return ans;
    }

    bool subset(map<int,int> a, map<int,int> b) {
        for (auto [p,x] : a)
            if (b[p] < x)
                return false;

        return true;
    }

    string smallestNumber(string num, long long t) {
        auto need = factorize(t);

        if (need.count(-1))
            return "-1";

        need.erase(-1);

        auto requiredDigits = getFactors(need);

        if (sum(requiredDigits) > num.size())
            return construct(requiredDigits);

        auto prefix = getFactors(num);

        int firstZero = num.find('0');

        if (firstZero == string::npos) {
            firstZero = num.size();

            if (subset(need, prefix))
                return num;
        }

        for (int i = num.size() - 1; i >= 0; i--) {
            int d = num[i] - '0';

            prefix = subtract(prefix, f[d]);

            int space = num.size() - 1 - i;

            if (i > firstZero)
                continue;

            for (int bigger = d + 1; bigger <= 9; bigger++) {
                auto remaining =
                    subtract(need, prefix);

                remaining =
                    subtract(remaining, f[bigger]);

                auto digits = getFactors(remaining);

                if (sum(digits) <= space) {
                    int ones = space - sum(digits);

                    return num.substr(0, i) +
                           char('0' + bigger) +
                           string(ones, '1') +
                           construct(digits);
                }
            }
        }

        auto digits = getFactors(need);

        return string(num.size() + 1 - sum(digits), '1') +
               construct(digits);
    }
};