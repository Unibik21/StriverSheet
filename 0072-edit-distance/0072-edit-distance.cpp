class Solution {
public:
    int solve(int i,int j,string &w1, string &w2,vector<vector<int>>&dp){
        if(i==w1.size()){
            return w2.size()-j;
        }
        if(j==w2.size()){
            return w1.size()-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j])return dp[i][j]=solve(i+1,j+1,w1,w2,dp);

        int op1 = 1+min(solve(i+1,j,w1,w2,dp),solve(i,j+1,w1,w2,dp));
        int op2 = 1+solve(i+1,j+1,w1,w2,dp);

        return dp[i][j]=min(op1,op2);
    }
    int minDistance(string w1, string w2) {
        vector<vector<int>>dp(w1.size(),vector<int>(w2.size(),-1));
        return solve(0,0,w1,w2,dp);
    }
};