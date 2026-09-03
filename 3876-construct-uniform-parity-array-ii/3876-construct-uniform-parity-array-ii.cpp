class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x & 1)
                minOdd = min(minOdd, x);
            else
                minEven = min(minEven, x);
        }

        // Already uniform parity.
        if (minOdd == INT_MAX || minEven == INT_MAX)
            return true;

        // We can make everything odd iff the smallest odd
        // number is smaller than every even number.
        return minOdd < minEven;
    }
};