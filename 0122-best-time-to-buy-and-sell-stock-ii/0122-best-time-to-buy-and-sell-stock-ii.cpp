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
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};