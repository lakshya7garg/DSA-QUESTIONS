class Solution {
public:
    
    long long heightReduced(vector<int>& workerTimes, long long T) {
        long long total=0;
        for (long long t:workerTimes) {
            long long x=(sqrt(1+8.0 * T/t)-1)/2;
            total+=x;
        }
        return total;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long left=1;
        long long right=1e16;

        while(left<right) {
            long long mid=left+(right-left)/2;
            if (heightReduced(workerTimes,mid)>=mountainHeight)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};