class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        return gcd(mini,maxi);
    }
};