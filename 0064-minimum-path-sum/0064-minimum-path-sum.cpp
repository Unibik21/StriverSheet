class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n-1][m-1]=grid[n-1][m-1];

        for(int j=0;j<=m;j++)dp[n][j]=1e9;
        for(int i=0;i<=n;i++)dp[i][m]=1e9;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;

                int right = dp[i][j+1];
                int down = dp[i+1][j];

                dp[i][j]=grid[i][j]+min(right,down);
            }
        }
        return dp[0][0];
    }
};