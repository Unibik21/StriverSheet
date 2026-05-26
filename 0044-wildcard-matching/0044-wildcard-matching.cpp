class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,0));
        dp[s.size()][p.size()]=1;
        for(int j=p.size()-1;j>=0;j--){
            if(p[j]=='*') dp[s.size()][j]=dp[s.size()][j+1];
            else dp[s.size()][j]=0;
        }

        for(int i=s.size()-1;i>=0;i--){
            for(int j=p.size()-1;j>=0;j--){
                if(s[i]==p[j] || p[j]=='?')dp[i][j]=dp[i+1][j+1];
                else if(p[j]=='*')dp[i][j]= dp[i+1][j] || dp[i][j+1];
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[0][0];
    }
};