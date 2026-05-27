class Solution {
public:
    int solve(int i,bool b, int cnt,vector<int>& p,vector<vector<vector<int>>>&dp){
        if(cnt==2 || i==p.size())return 0;
        if(dp[i][b][cnt]!=-1)return dp[i][b][cnt]; 
        int prof =0;
        if(b){
            int buy = -p[i]+solve(i+1,0,cnt,p,dp);
            int notbuy = solve(i+1,1,cnt,p,dp);

            prof = max(buy,notbuy);
        }
        else{
            int sell = +p[i]+solve(i+1,1,cnt+1,p,dp);
            int notsell = solve(i+1,0,cnt,p,dp);

            prof = max(sell,notsell);
        }
        return dp[i][b][cnt]=prof;
    }
    int maxProfit(vector<int>& p) {
        vector<vector<vector<int>>>dp(p.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,0,p,dp);
    }
};