class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<int>& vis) {
        int n = arr.size();
        //out of bounds or already visited
        if (start < 0 || start >= n || vis[start])
            return false;

        //found zero
        if (arr[start] == 0)
            return true;

        vis[start] = 1;

        //jump forward or backward
        return dfs(arr, start + arr[start], vis) ||
               dfs(arr, start - arr[start], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return dfs(arr, start, vis);
    }
};