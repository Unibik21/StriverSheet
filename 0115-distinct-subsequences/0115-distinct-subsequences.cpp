class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==s.size() && j==t.size()){
            return 1;
        }
        if(i==s.size())return 0;
        if(j==t.size())return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =0;
        if(s[i]==t[j]){
            int take = solve(i+1,j+1,s,t,dp);
            ans+=take;
        }
        int nottake = solve(i+1,j,s,t,dp);
        ans+=nottake;

        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t,dp);
    }
};