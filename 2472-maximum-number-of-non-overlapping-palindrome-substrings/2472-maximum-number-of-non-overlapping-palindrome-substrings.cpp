class Solution {
public:
    bool check(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int x,int last,string &s,int &k,vector<vector<vector<int>>>&dp){
        if(i==s.size())return 0;
        if(dp[i][x][last+1]!=-1)return dp[i][x][last+1];
        int ans =0;
        if(x){
            int one = -1e9;
            if(i-last+1>=k && check(s,last,i)){
                one = 1+solve(i+1,0,i,s,k,dp);
            }
            int two = solve(i+1,1,last,s,k,dp);
            ans = max(one,two);
        }
        else{
            int take = solve(i+1,1,i,s,k,dp);
            int nottake = solve(i+1,0,last,s,k,dp);
            ans = max(take,nottake);
        }
        return dp[i][x][last+1]=ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1)return n;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(n+1,-1)));
        return solve(0,0,-1,s,k,dp);
    }
};