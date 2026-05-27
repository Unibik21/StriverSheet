class Solution {
public:
    int solve(int i,bool b,vector<int>&p,vector<vector<int>>&dp){
        if(i==p.size())return 0;
        if(dp[i][b]!=-1)return dp[i][b];
        int profit = 0;

        if(b){
            int take = -p[i]+solve(i+1,0,p,dp);
            int nottake = solve(i+1,1,p,dp);
            profit = max(take,nottake);
        }
        else{
            int sell = p[i]+solve(i+1,1,p,dp);
            int notsell = solve(i+1,0,p,dp);
            profit = max(sell,notsell);
        }

        return dp[i][b]=profit;
    }
    int maxProfit(vector<int>& p) {
        vector<vector<int>>dp(p.size()+1,vector<int>(2,0));
        

        for(int i=p.size()-1;i>=0;i--){
            int take = -p[i]+dp[i+1][0];
            int nottake = dp[i+1][1];
            dp[i][1] = max(take,nottake);
           
            int sell = p[i]+dp[i+1][1];
            int notsell = dp[i+1][0];
            dp[i][0] = max(sell,notsell);
        }

        return dp[0][1];
    }
};