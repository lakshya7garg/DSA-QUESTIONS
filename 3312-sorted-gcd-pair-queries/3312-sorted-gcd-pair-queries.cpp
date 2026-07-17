class Solution {
public:
#define ll long long
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        ll n=nums.size();
        ll m=queries.size();

        ll mx=*max_element(nums.begin(),nums.end());

        vector<ll> freq(mx+1,0);
        for(ll i=0;i<n;i++){
            freq[nums[i]]++;
        }

        vector<ll> cnt(mx+1,0);
        for(ll i=1;i<=mx;i++){
            for(ll j=i;j<=mx;j+=i){
                cnt[i]+=freq[j];
            }
        }

        vector<ll> gcdpairs(mx+1,0);
        for(ll i=mx;i>=1;i--){
            gcdpairs[i]=cnt[i]*(cnt[i]-1)/2;
            for(ll j=2*i;j<=mx;j+=i){
                gcdpairs[i]-=gcdpairs[j];
            }
        }

        vector<ll> prefix(mx+1,0);
        for(ll i=1;i<=mx;i++){
            prefix[i]=prefix[i-1]+gcdpairs[i];
        }

        vector<int> answer(m);
        for(ll i=0;i<m;i++){
            answer[i]=lower_bound(prefix.begin()+1,prefix.end(),queries[i]+1)-prefix.begin();
        }

        return answer;
    }
};