class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Try making the first difference at i.
            // Since we want the lexicographically smallest answer,
            // use the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] == 0)
                    continue;

                string cur = target.substr(0, i);
                cur += char('a' + c);

                vector<int> remaining = cnt;
                remaining[c]--;

                for (int k = 0; k < 26; k++) {
                    cur += string(remaining[k], char('a' + k));
                }

                // Later i means a longer equal prefix, so it is
                // automatically lexicographically smaller.
                ans = cur;
                break;
            }

            // Continue only if target[i] can be matched.
            if (cnt[x] == 0)
                break;

            cnt[x]--;
        }

        return ans;
    }
};