class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        vector<vector<vector<int>>>dp(p.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int i=p.size()-1;i>=0;i--){
            for(int b=1;b>=0;b--){
                for(int cnt =k-1;cnt>=0;cnt--){
                    int prof =0;
                    if(b){
                        int buy = -p[i]+dp[i+1][0][cnt];
                        int notbuy = dp[i+1][1][cnt];

                        prof = max(buy,notbuy);
                    }
                    else{
                        int sell = p[i]+dp[i+1][1][cnt+1];
                        int notsell = dp[i+1][0][cnt];

                        prof = max(sell,notsell);
                    }
                    dp[i][b][cnt]=prof;
                }
            }
        }
        return dp[0][1][0];
    }
};