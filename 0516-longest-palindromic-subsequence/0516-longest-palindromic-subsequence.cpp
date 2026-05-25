class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));

        for(int i=s.size()-1;i>=0;i--){
            for(int j=s.size()-1;j>=0;j--){
                if(s[i]==t[j]){   
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        } 
        return dp[0][0];
    }
};