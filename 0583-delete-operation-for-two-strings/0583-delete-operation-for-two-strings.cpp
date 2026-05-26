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
        if(w1[i]==w2[j]){
            return dp[i][j]=solve(i+1,j+1,w1,w2,dp);
        }

        return dp[i][j]=1+min(solve(i+1,j,w1,w2,dp),solve(i,j+1,w1,w2,dp));
    }
    int minDistance(string w1, string w2) {
        vector<vector<int>>dp(w1.size()+1,vector<int>(w2.size()+1,0));
        

        for(int i=0;i<=w1.size();i++){
            dp[i][w2.size()]=w1.size()-i;
        }
        for(int i=0;i<=w2.size();i++){
            dp[w1.size()][i]=w2.size()-i;
        }

        for(int i=w1.size()-1;i>=0;i--){
            for(int j=w2.size()-1;j>=0;j--){
                if(w1[i]==w2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]); 
                }
            }
        }
        return dp[0][0];

    }
};