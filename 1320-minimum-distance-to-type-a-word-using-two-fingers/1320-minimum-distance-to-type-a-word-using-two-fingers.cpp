class Solution {
public:
    int dist(int n1,int n2){
        if(n2==26)return 0;

        int r1 = n1/6;
        int c1 = n1%6;
        int r2 = n2/6;
        int c2 = n2%6;

        return abs(r1-r2)+abs(c1-c2);
    }
    int solve(int i,string &word,int f1,int f2,vector<vector<vector<int>>>&dp){
        if(i==word.size())return 0;
        if(dp[i][f1][f2]!=-1)return dp[i][f1][f2];

        int curr = word[i]-'A';

        int one = dist(curr,f1)+solve(i+1,word,curr,f2,dp);
        int two = dist(curr,f2)+solve(i+1,word,curr,f1,dp);

        return dp[i][f1][f2]=min(one,two);
    }
    int minimumDistance(string word) {
        vector<vector<vector<int>>>dp(word.size(),vector<vector<int>>(27,vector<int>(27,-1)));
        return solve(0,word,26,26,dp);
    }
};