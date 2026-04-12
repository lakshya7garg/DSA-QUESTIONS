class Solution {
public:
    int memo[301][27][27];

    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0; // unused finger
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int solve(string &word, int i, int f1, int f2) {
        if (i == word.size()) return 0;

        int &ans = memo[i][f1][f2];
        if (ans != -1) return ans;

        int cur = word[i] - 'A';

        // Use finger 1 to type current character
        int useF1 = dist(f1, cur) + solve(word, i + 1, cur, f2);

        // Use finger 2 to type current character
        int useF2 = dist(f2, cur) + solve(word, i + 1, f1, cur);

        return ans = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        return solve(word, 0, 26, 26);
    }
};