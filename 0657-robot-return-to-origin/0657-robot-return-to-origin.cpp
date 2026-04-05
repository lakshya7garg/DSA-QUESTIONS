class Solution {
public:
    bool judgeCircle(string s) {
        if(s.empty()) return true;
        int cR=0,cL=0,cU=0,cD=0;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(s[i]=='R') cR++;
            if(s[i]=='L') cL++;
            if(s[i]=='D') cD++;
            if(s[i]=='U') cU++;
        }
        if(cR==cL && cU==cD) return true;
        return false;
    }
};