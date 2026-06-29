class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size()));
        int ans=0;

        for(int i=0;i<mat.size();i++){dp[i][0]=mat[i][0]; if(mat[i][0]==1)ans+=1;}
        for(int j=1;j<mat[0].size();j++){dp[0][j]=mat[0][j]; if(mat[0][j]==1)ans+=1;}
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                if(mat[i][j]==0)dp[i][j]=0;
                else{
                    dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    ans+=dp[i][j];
                }
            }
        }

        return ans;
    }
};