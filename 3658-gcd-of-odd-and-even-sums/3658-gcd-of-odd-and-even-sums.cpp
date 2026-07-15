class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum=0,evenSum=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0) evenSum+=i;
            else oddSum+=i;
        }
        return gcd(oddSum,evenSum);
    }
};