class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        for (auto &p : points) {
            long long x = p[0], y = p[1];

            if (x == 0) {
                pos.push_back(y);
            } 
            else if (y == side) {
                pos.push_back(side + x);
            } 
            else if (x == side) {
                pos.push_back(3LL * side - y);
            } 
            else {
                pos.push_back(4LL * side - x);
            }
        }

        sort(pos.begin(), pos.end());

        int low = 0, high = side, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can(pos, side, k, mid)) {
                ans = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool can(vector<long long>& pos, int side, int k, int d) {
        int n = pos.size();
        long long perimeter = 4LL * side;

        vector<long long> arr = pos;
        for (long long x : pos) {
            arr.push_back(x + perimeter);
        }

        for (int i = 0; i < n; i++) {
            long long start = arr[i];
            long long cur = start;
            long long lastAllowed = start + perimeter - d;

            int idx = i;
            bool ok = true;

            for (int count = 1; count < k; count++) {
                auto it = lower_bound(arr.begin() + idx + 1,
                                      arr.begin() + i + n,
                                      cur + d);

                if (it == arr.begin() + i + n || *it > lastAllowed) {
                    ok = false;
                    break;
                }

                idx = it - arr.begin();
                cur = *it;
            }

            if (ok) return true;
        }

        return false;
    }
};