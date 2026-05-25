class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<long long>>dp(coins.size()+1,vector<long long>(amount+1,0));
        for(int i=0;i<=coins.size();i++)dp[i][0]=1;
        for(int i=coins.size()-1;i>=0;i--){
            for(int amt = 1;amt<=amount;amt++){
                long long nottake = dp[i+1][amt];
                long long take =0;
                if(coins[i]<=amt)take = dp[i][amt-coins[i]];
                if(take+nottake>INT_MAX)dp[i][amt]=INT_MAX;
                else dp[i][amt]=nottake+take;
            }
        }
        return (int)dp[0][amount];
    }
};