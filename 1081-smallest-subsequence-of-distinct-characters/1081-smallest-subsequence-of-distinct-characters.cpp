class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26), vis(26, 0);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string ans;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (vis[c]) continue;

            while (!ans.empty() &&
                   ans.back() > s[i] &&
                   last[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            vis[c] = 1;
        }

        return ans;
    }
};