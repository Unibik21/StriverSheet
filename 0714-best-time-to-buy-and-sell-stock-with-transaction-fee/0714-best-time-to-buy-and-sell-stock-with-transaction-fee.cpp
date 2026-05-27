class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        vector<vector<int>>dp(p.size()+1,vector<int>(2,0));
        for(int i=p.size()-1;i>=0;i--){
            for(int b=1;b>=0;b--){
                int prof =0;
                if(b){
                    int buy = -p[i]+dp[i+1][0];
                    int notbuy = dp[i+1][1];
                    prof = max(buy,notbuy);
                }
                else{
                    int sell = p[i]+dp[i+1][1]-fee;
                    int notsell = dp[i+1][0];
                    prof = max(sell,notsell);
                }
                dp[i][b]=prof;
            }
        }
        return dp[0][1];
    }
};