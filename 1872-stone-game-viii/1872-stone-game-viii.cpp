class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int>pref(stones.size(),0);
        pref[0]=stones[0];
        for(int i=1;i<stones.size();i++){
            pref[i]=pref[i-1]+stones[i];
        }
        vector<int>dp(stones.size(),0);
        dp[pref.size()-1]=pref[pref.size()-1];

        for(int i=stones.size()-2;i>=1;i--){
            int take = pref[i]-dp[i+1];
            int skip = dp[i+1];
            dp[i]=max(take,skip);
        }

        return dp[1];
    }
};