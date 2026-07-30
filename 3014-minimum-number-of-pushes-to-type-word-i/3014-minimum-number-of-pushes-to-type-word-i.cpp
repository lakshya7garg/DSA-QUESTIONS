class Solution {
public:
    int minimumPushes(string word) {
        int l=word.length();
        if(l<=8) return l;
        else if(l<=16) return 8+2*(l-8);
        else if(l<=24) return 8+16+3*(l-16);
        else return 8+16+24+4*(l-24);
    }
};