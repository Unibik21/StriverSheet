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
        vector<vector<int>>dp(p.size()+1,vector<int>(2,-1));
        return solve(0,1,p,dp);
    }
};