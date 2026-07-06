class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end(),cmp);

        int ans=0;
        int maxEnd=-1;

        for(auto &x: intervals){
            if(x[1]>maxEnd){
                ans++;
                maxEnd=x[1];
            }
        }
        return ans;
    }
};