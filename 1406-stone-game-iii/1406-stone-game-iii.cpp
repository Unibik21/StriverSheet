class Solution {
public:
    int solve(int i,vector<int>& s,vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int res = INT_MIN; 
        res = max(res,s[i]-solve(i+1,s,dp));
        if(i+1<s.size())res = max(res,s[i]+s[i+1]-solve(i+2,s,dp));
        if(i+2<s.size())res= max(res,s[i]+s[i+1]+s[i+2]-solve(i+3,s,dp));

        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),-1);
        int ans = solve(0,stoneValue,dp);
        if(ans>0)return "Alice";
        else if(ans<0)return "Bob";
        return "Tie";
    }
};