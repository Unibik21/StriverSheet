class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int reachable =0;
        vector<bool>dp(s.size(),false);
        dp[0]=true;
        for(int i=1;i<s.size();i++){
            
            if(i-minJump>=0 && dp[i-minJump])reachable++;
            if(i-maxJump-1>=0 && dp[i-maxJump-1])reachable--;
            if(s[i]=='0' && reachable>0)dp[i]=true;
        }

        return dp[s.size()-1];
    }
};