class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = word2[j] ko match karne wala
        // right side se milne wala index
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Right se word2 ko match kar rahe hain
        // taaki pata rahe ki remaining characters
        // future me kaha se match ho sakte hain
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        bool canChange = true;
        j = 0;

        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Exact match -> directly le lo
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Mismatch hai, to ek baar change allowed hai
            // Lekin change tabhi karenge jab remaining word2
            // ko baad me match karna possible ho
            else if (canChange &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;
                canChange = false;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};