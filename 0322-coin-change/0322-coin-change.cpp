class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,1e9));
        for(int i=0;i<coins.size();i++)dp[i][0]=0;

        for(int i=coins.size()-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int nottake = dp[i+1][j];
                int take = 1e9;
                if(coins[i]<=j)take = 1+dp[i][j-coins[i]];
                dp[i][j]=min(take,nottake);
            }
        }
        return dp[0][amount]==1e9?-1:dp[0][amount];
    }
};