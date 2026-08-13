//not done by me ...
class Solution {
    struct Node {
        char lc, rc;
        int ll, rr, best, len;

        Node() : lc(0), rc(0), ll(0), rr(0), best(0), len(0) {}

        Node(char c) : lc(c), rc(c), ll(1), rr(1), best(1), len(1) {}
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.ll = a.ll;
        if (a.ll == a.len && a.rc == b.lc)
            res.ll = a.len + b.ll;

        res.rr = b.rr;
        if (b.rr == b.len && a.rc == b.lc)
            res.rr = b.len + a.rr;

        res.best = max(a.best, b.best);

        if (a.rc == b.lc)
            res.best = max(res.best, a.rr + b.ll);

        return res;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            seg[p] = Node(s[l]);
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, char c) {
        if (l == r) {
            seg[p] = Node(c);
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, c);
        else
            update(p * 2 + 1, m + 1, r, idx, c);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};