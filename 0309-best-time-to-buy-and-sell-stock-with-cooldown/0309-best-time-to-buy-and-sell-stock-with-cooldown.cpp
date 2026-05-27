class Solution {
public:
    int solve(int i,bool b,vector<int>& p,vector<vector<int>>&dp){
        if(i>=p.size())return 0;
        if(dp[i][b]!=-1)return dp[i][b];
        int prof =0;
        if(b){
            int buy = -p[i]+solve(i+1,0,p,dp);
            int notbuy = solve(i+1,1,p,dp);
            prof = max(buy,notbuy);
        }
        else{
            int sell = p[i]+solve(i+2,1,p,dp);
            int notsell = solve(i+1,0,p,dp);
            prof = max(sell,notsell);
        }
        return dp[i][b]=prof;
    }
    int maxProfit(vector<int>& p){
        vector<vector<int>>dp(p.size()+2,vector<int>(2,0));
        for(int i=p.size()-1;i>=0;i--){
            for(int b=1;b>=0;b--){
                int prof =0;
                if(b){
                    int buy = -p[i]+dp[i+1][0];
                    int notbuy = dp[i+1][1];
                    prof = max(buy,notbuy);
                }
                else{
                    int sell = p[i]+dp[i+2][1];
                    int notsell = dp[i+1][0];
                    prof = max(sell,notsell);
                }
                dp[i][b]=prof;
            }
        }
        return dp[0][1];
    }
};