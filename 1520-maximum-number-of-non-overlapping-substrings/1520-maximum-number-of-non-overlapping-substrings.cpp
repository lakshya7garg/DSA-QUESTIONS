class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, -1), r(26, -1);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (l[s[i] - 'a'] == -1)
                l[s[i] - 'a'] = i;
            r[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> v;

        for (int i = 0; i < 26; i++) {
            if (l[i] == -1) continue;

            int L = l[i], R = r[i];
            bool ok = true;

            for (int j = L; j <= R; j++) {
                int c = s[j] - 'a';
                if (l[c] < L) {
                    ok = false;
                    break;
                }
                R = max(R, r[c]);
            }

            if (ok) v.push_back({L, R});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for (auto &[L, R] : v) {
            if (L > end) {
                ans.push_back(s.substr(L, R - L + 1));
                end = R;
            }
        }

        return ans;
    }
};