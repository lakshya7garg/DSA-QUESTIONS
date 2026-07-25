class Solution {
public:
    int maxProduct(int n) {
        int m1=0,m2=0;
        while(n){
            int r=n%10;
            if(r>=m1){
                m2=m1;
                m1=r;
            }else if(r>m2){
                m2=r;
            }
            n/=10;
        }
        return m1*m2;
    }
};