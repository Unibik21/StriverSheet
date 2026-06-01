class Solution {
public:
    bool isP(int i,int j,string &s){
        if(i==j)return true;

        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string &s,vector<int>&dp){
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = 1e9;
        for(int k=i;k<s.size();k++){
            if(isP(i,k,s)){
                mini=min(mini,1+solve(k+1,s,dp));
            }
        }

        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return solve(0,s,dp)-1;
    }
};