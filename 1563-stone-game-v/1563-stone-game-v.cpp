class Solution {
public:
    int solve(int i,int j,vector<int>&s,int sum,vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int sum1 = 0;
        int total =0;
        for(int k=i;k<j;k++){
            sum1+=s[k];
            int sum2 = sum-sum1;
            int first = sum1+solve(i,k,s,sum1,dp);
            int second = sum2+solve(k+1,j,s,sum2,dp);
            if(sum1<sum2){
                total= max(total,first);
            }
            else if(sum1>sum2){
                total= max(total,second);
            }
            else{
                total = max(first,second);
            }
        }

        return dp[i][j]=total;
    }
    int stoneGameV(vector<int>& s) {
        int sum =0;
        for(auto &i:s)sum+=i;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return solve(0,s.size()-1,s,sum,dp);
    }
};