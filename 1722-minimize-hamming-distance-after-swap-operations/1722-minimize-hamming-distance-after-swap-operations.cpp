class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }

        unordered_map<int, unordered_map<int, int>> freq;

        for (int i = 0; i < n; i++) {
            freq[find(i)][source[i]]++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (freq[p][target[i]] > 0) {
                freq[p][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};