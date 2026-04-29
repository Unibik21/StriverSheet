class Solution {
public:
    typedef long long ll;
    int n;
    ll solve(bool pTaken,int prevht,int col,vector<vector<int>>& grid,vector<vector<ll>>&pSum,vector<vector<vector<ll>>>&dp){
        if(col==n)return 0;
        
        ll res = 0;
        if(dp[pTaken][col][prevht]!=-1)return dp[pTaken][col][prevht];
        for(int ht =0;ht<=n;ht++){
            ll prevScore = 0;
            ll currScore = 0;

            if(!pTaken && ht>prevht && col>0){
                prevScore = pSum[ht][col]-pSum[prevht][col];
            }
            if(prevht>ht){
                currScore = pSum[prevht][col+1]-pSum[ht][col+1];
            }

            ll currTaken = currScore + solve(true,ht,col+1,grid,pSum,dp);
            ll NotTaken = prevScore + solve(false,ht,col+1,grid,pSum,dp);

            res = max({res,currTaken,NotTaken});
        }  

        return dp[pTaken][col][prevht] = res;
    }
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<ll>>pSum(n+1,vector<ll>(n+1,0));
        vector<vector<vector<ll>>>dp(2,vector<vector<ll>>(grid[0].size()+1,vector<ll>(grid.size()+1,-1)));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                pSum[i][j]=pSum[i-1][j]+grid[i-1][j-1];
            }
        }

        return solve(false,0,0,grid,pSum,dp);

    }
};