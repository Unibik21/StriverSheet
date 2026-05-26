class Solution {
public:
    int minDistance(string w1, string w2) {
        vector<vector<int>>dp(w1.size()+1,vector<int>(w2.size()+1,0));
        
        for(int i=0;i<=w1.size();i++)dp[i][w2.size()]=w1.size()-i;
        for(int i=0;i<=w2.size();i++)dp[w1.size()][i]=w2.size()-i;

        for(int i=w1.size()-1;i>=0;i--){
            for(int j=w2.size()-1;j>=0;j--){
                if(w1[i]==w2[j])dp[i][j]=dp[i+1][j+1];
                else{
                    dp[i][j] = min({1+dp[i+1][j+1],1+dp[i+1][j],1+dp[i][j+1]});
                }
            }
        }
        return dp[0][0];
    }
};