class Solution {
public:
    bool solve(int l,int r,bool turn,int s1,int s2,vector<int>& piles,vector<vector<vector<int>>>&dp){
        if(l>r)return s1>s2;
        if(dp[l][r][turn]!=-1)return dp[l][r][turn];
        if(turn){
            return dp[l][r][turn] = solve(l+1,r,0,s1+piles[l],s2,piles,dp) || solve(l,r-1,0,s1+piles[r],s2,piles,dp);
        }
        else{
            return dp[l][r][turn] = solve(l+1,r,1,s1,s2+piles[l],piles,dp) || solve(l,r-1,1,s1,s2+piles[r],piles,dp);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,piles.size()-1,1,0,0,piles,dp);
    }
};