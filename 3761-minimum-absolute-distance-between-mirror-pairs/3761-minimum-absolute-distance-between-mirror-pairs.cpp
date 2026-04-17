class Solution {
public:
    int reversenum(int x){
        int rev=0;
        while(x>0){
            rev=rev*10+(x%10);
            x/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> last;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int rev=reversenum(nums[i]);
            if(last.count(nums[i])){
                ans=min(ans,i-last[nums[i]]);
            }
        last[rev]=i;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};