class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(), n=coins[0].size();
        const long long NEG=-1e18;

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n,        vector<long long>(3, NEG)));

        //start cell
        if(coins[0][0] >= 0) {
            dp[0][0][0]=coins[0][0];
        }else{
            dp[0][0][0]=coins[0][0]; //don't neutralize
            dp[0][0][1]=0;           //neutralize this robber
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue;

                for(int k=0; k<=2; k++) {
                    long long bestPrev=NEG;

                    if(i>0) 
                        bestPrev=max(bestPrev, dp[i-1][j][k]);
                    if(j>0) 
                        bestPrev=max(bestPrev, dp[i][j-1][k]);

                    if(bestPrev!=NEG) {
                        dp[i][j][k]=max(dp[i][j][k],bestPrev+coins[i][j]);
                    }

                    //neutralize current robber if negative
                    if(coins[i][j]<0 && k>0){
                        long long bestPrevNeutral=NEG;
                        if(i>0) 
                            bestPrevNeutral=max(bestPrevNeutral,dp[i-1][j][k-1]);
                        if(j>0) 
                            bestPrevNeutral=max(bestPrevNeutral,dp[i][j-1][k-1]);

                        if(bestPrevNeutral!=NEG) {
                            dp[i][j][k]=max(dp[i][j][k],bestPrevNeutral);
                        }
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};