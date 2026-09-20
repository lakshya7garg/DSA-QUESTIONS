class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int val = 'z' - s[i] + 1;
            ans += val * (i + 1);
        }

        return ans;
    }
};