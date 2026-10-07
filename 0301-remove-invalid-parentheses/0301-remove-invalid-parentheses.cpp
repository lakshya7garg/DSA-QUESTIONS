class Solution {
public:
    vector<string> ans;

    void solve(string &s, int i, int l, int r, int open,
               string &cur, bool prevDeleted) {
        if (i == s.size()) {
            if (l == 0 && r == 0 && open == 0)
                ans.push_back(cur);
            return;
        }

        if (s[i] == '(') {
            // delete
            if (l > 0 && !(i > 0 && s[i - 1] == '(' && !prevDeleted))
                solve(s, i + 1, l - 1, r, open, cur, true);

            // keep
            cur.push_back('(');
            solve(s, i + 1, l, r, open + 1, cur, false);
            cur.pop_back();
        }
        else if (s[i] == ')') {
            // delete
            if (r > 0 && !(i > 0 && s[i - 1] == ')' && !prevDeleted))
                solve(s, i + 1, l, r - 1, open, cur, true);

            // keep
            if (open > 0) {
                cur.push_back(')');
                solve(s, i + 1, l, r, open - 1, cur, false);
                cur.pop_back();
            }
        }
        else {
            cur.push_back(s[i]);
            solve(s, i + 1, l, r, open, cur, false);
            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();

        int l = 0, r = 0;

        for (char c : s) {
            if (c == '(')
                l++;
            else if (c == ')') {
                if (l > 0)
                    l--;
                else
                    r++;
            }
        }

        string cur;
        solve(s, 0, l, r, 0, cur, false);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};