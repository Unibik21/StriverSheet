class Solution {
public:
    int m,n;
    int solve(int i,int j,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n)return INT_MIN;
        if(k<0){
           return INT_MIN; 
        }
        int cost = grid[i][j]>0?1:0;
        if(i==m-1 && j==n-1){
            if(k - cost >= 0) return grid[i][j];
            return INT_MIN;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int rt = INT_MIN;
        int sum1 = solve(i,j+1,k-cost,grid,dp);
        if(sum1!=INT_MIN){
            rt = grid[i][j]+sum1;
        }
        int dn = INT_MIN;
        int sum2 = solve(i+1,j,k-cost,grid,dp);
        if(sum2!=INT_MIN){
            dn = grid[i][j]+sum2;
        }

        return dp[i][j][k]=max(rt,dn);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int ans = solve(0,0,k,grid,dp);

        return ans==INT_MIN?-1:ans;
    }
};