class Solution {
public:
    int solve(int i,int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i==mat.size()-1 && j==mat[0].size()-1)return 1;
        if(i>mat.size()-1 || j>mat[0].size()-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right = 0;
        int down= 0;

        if(j<mat[0].size()-1 && mat[i][j+1]!=1)right = solve(i,j+1,mat,dp);
        if(i<mat.size()-1 && mat[i+1][j]!=1)down = solve(i+1,j,mat,dp);

        return dp[i][j]=right+down; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        if(mat[0][0]==1 || mat[mat.size()-1][mat[0].size()-1]==1)return 0;
        vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size(),-1));
        return solve(0,0,mat,dp);
    }
};