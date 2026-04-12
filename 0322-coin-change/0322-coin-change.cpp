class Solution {
public:
    int solve(int i,int curr,vector<int>&coins,int total,vector<vector<int>>&dp){
        if(curr==total)return 0;
        if(i==coins.size()){
            if(curr==total) return 0;
            else return 1e9;
        }
        if(dp[i][curr]!=-1) return dp[i][curr];
        int take = INT_MAX;
        if((long long)curr+coins[i]<=total){
            take= 1+solve(i,curr+coins[i],coins,total,dp);
        }
        int nottake = solve(i+1,curr,coins,total,dp);

        return dp[i][curr]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount,-1));
        int ans = solve(0,0,coins,amount,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};