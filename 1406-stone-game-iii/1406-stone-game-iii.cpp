class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        vector<int>dp(s.size()+1,0);
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            int res = INT_MIN; 
            res = max(res,s[i]-dp[i+1]);
            if(i+1<s.size())res = max(res,s[i]+s[i+1]-dp[i+2]);
            if(i+2<s.size())res= max(res,s[i]+s[i+1]+s[i+2]-dp[i+3]);
            dp[i]=res;
        }
        if(dp[0]>0)return "Alice";
        else if(dp[0]<0)return "Bob";
        return "Tie";
    }
};