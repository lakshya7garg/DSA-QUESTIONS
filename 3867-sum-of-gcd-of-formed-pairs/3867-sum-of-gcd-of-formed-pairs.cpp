class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n);
        vector<int> mx(n);
        mx[0]=nums[0];
        prefixGcd[0]=gcd(nums[0],mx[0]);
        for(int i=1;i<n;i++){
            mx[i]=max(nums[i],mx[i-1]);
            prefixGcd[i]=gcd(nums[i],mx[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int left=0,right=n-1;
        int sum=0;
        while(left<right){
            int temp=gcd(prefixGcd[left],prefixGcd[right]);
            sum+=temp;
            left++;
            right--;
        }
        return sum;
    }
};