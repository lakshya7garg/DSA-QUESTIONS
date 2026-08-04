class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        unordered_set<int> s;
        for(int x:nums){
            mn=min(mn,x);
            mx=max(mx,x);
            s.insert(x);
        }

        vector<int> ans;
        for(int x=mn+1;x<mx;x++){
            if(s.find(x)==s.end()){
                ans.push_back(x);
            }
        }

        return ans;
    }
};