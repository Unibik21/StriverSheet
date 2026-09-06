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
        vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
        // return solve(0,0,s,t,dp);

        dp[s.size()][t.size()]=1;
        for(int i=0;i<s.size();i++)dp[i][t.size()]=1;

        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                double ans =0;
                if(s[i]==t[j]){
                    double take = dp[i+1][j+1];
                    ans+=take;
                }
                double nottake = dp[i+1][j];
                ans+=nottake;

                dp[i][j]=ans;
            }
        }
        return (int)dp[0][0];
    }
};