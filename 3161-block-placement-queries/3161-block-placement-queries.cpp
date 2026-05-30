class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.assign(4 * n + 4, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(ql, qr, 2 * node, l, mid),
            query(ql, qr, 2 * node + 1, mid + 1, r)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 1, 0, n);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int mx = 0;
        for (auto &q : queries)
            mx = max(mx, q[1]);

        set<int> pos = {0, mx + 1};

        SegmentTree seg(mx + 1);

        seg.update(0, mx + 1);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {
                int x = q[1];

                auto itR = pos.upper_bound(x);
                auto itL = prev(itR);

                int L = *itL;
                int R = *itR;

                seg.update(L, x - L);
                seg.update(x, R - x);

                pos.insert(x);
            }
            else {
                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);
                int leftObs = *prev(it);

                int best = seg.query(0, leftObs - 1);

                // partial interval containing x
                best = max(best, x - leftObs);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};