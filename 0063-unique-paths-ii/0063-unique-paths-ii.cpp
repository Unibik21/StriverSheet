class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        if(mat[0][0]==1 || mat[mat.size()-1][mat[0].size()-1]==1)return 0;
        vector<vector<long long>>dp(mat.size(),vector<long long>(mat[0].size(),0));
        int n = mat.size();
        int m = mat[0].size();

        dp[n-1][m-1]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;
                if(mat[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                long long right = 0;
                long long down = 0;

                if(j+1 < m)
                    right = dp[i][j+1];

                if(i+1 < n)
                    down = dp[i+1][j];

                dp[i][j] = right + down;
            }
        }

        return (int)dp[0][0];
    }
};